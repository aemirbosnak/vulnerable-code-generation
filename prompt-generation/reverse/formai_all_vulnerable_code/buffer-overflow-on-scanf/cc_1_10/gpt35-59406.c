//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_EXT_LEN 16
#define MAX_FILE_EXT_LIST_SIZE 1024

struct file_ext {
    char ext[MAX_FILE_EXT_LEN];
    unsigned long long int size;
};

int compare(const void *a, const void *b){
    struct file_ext *file_ext_a = (struct file_ext *)a;
    struct file_ext *file_ext_b = (struct file_ext *)b;

    if(file_ext_a->size > file_ext_b->size){
        return -1;
    }
    if(file_ext_a->size < file_ext_b->size){
        return 1;
    }
    return 0;
}

int is_file_valid(char *filename){
    char *dot_pos = strrchr(filename, '.');
    if(dot_pos == NULL){
        return 0;
    }    
    if(strlen(dot_pos) < 2 || strlen(dot_pos) > MAX_FILE_EXT_LEN-1){
        return 0;
    }
    return 1;
}

int main(){
    char file_name[MAX_FILE_NAME_LEN];
    unsigned int file_ext_list_size = 0;
    struct file_ext file_ext_list[MAX_FILE_EXT_LIST_SIZE] = {0};
    
    printf("Enter root directory path: ");
    scanf("%s", file_name);

    FILE *fp = popen("du -a ", "r");

    if(fp == NULL){
        printf("Error: Could not open pipe.\n");
        return -1;
    }

    char line[1024] = {0};
    while(fgets(line, sizeof(line)-1, fp)){
        char *pos = strstr(line, file_name);
        if(pos != NULL){
            pos += strlen(file_name);
            if(is_file_valid(pos)){
                char *file_ext = strrchr(pos, '.')+1;
                unsigned long long int file_size = strtoull(line, NULL, 10);
                if(file_size > 0){
                    int found_index = -1;
                    for(int i=0; i<file_ext_list_size; i++){
                        if(strcasecmp(file_ext, file_ext_list[i].ext) == 0){
                            found_index = i;
                            break;
                        }
                    }
                    if(found_index == -1){
                        strncpy(file_ext_list[file_ext_list_size].ext, file_ext, MAX_FILE_EXT_LEN-1);
                        file_ext_list[file_ext_list_size].size = file_size;
                        ++file_ext_list_size;
                    } else {
                        file_ext_list[found_index].size += file_size;
                    }
                }
            }
        }
        memset(line, 0, sizeof(line));
    }
    pclose(fp);

    qsort(file_ext_list, file_ext_list_size, sizeof(struct file_ext), compare);

    printf("\n%d file extensions found.\n\n", file_ext_list_size);
    
    printf("%-6s %3s %4s  %s\n", "RANK", "EXT", "SIZE", "FILE TYPE");
    printf("====================================\n");

    for(int i=0; i<file_ext_list_size; i++){
        int size_in_KB = file_ext_list[i].size/1024;
        int size_in_MB = size_in_KB/1024;

        if(size_in_MB > 0){
            printf("%-6d %-3s %4dMB  binaries\n", i+1, file_ext_list[i].ext, size_in_MB);
        } else if(size_in_KB > 0){
            printf("%-6d %-3s %4dKB  binaries\n", i+1, file_ext_list[i].ext, size_in_KB);
        } else {
            printf("%-6d %-3s %4lldB  binaries\n", i+1, file_ext_list[i].ext, file_ext_list[i].size);
        }
    }
    return 0;
}