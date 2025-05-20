//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void *load_directory(void *arg) {
    DIR *dir;
    struct dirent *ent;
    char path[100];
    
    sprintf(path, "%s", (char *) arg);
    
    dir = opendir(path);
    
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char filename[100];
            sprintf(filename, "%s/%s", path, ent->d_name);
            
            FILE *file;
            file = fopen(filename, "r");
            
            if (file!= NULL) {
                char line[100];
                while (fgets(line, sizeof(line), file)!= NULL) {
                    if (sscanf(line, "%s %s", entries[num_entries].name, entries[num_entries].number) == 2) {
                        num_entries++;
                    }
                }
                fclose(file);
            }
        }
    }
    
    closedir(dir);
}

int main() {
    pthread_t thread_id;
    char dir_path[100];
    
    printf("Enter directory path: ");
    scanf("%s", dir_path);
    
    pthread_create(&thread_id, NULL, load_directory, (void *) dir_path);
    
    while (num_entries == 0) {
        sleep(1);
    }
    
    printf("Phone Book:\n");
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
    
    return 0;
}