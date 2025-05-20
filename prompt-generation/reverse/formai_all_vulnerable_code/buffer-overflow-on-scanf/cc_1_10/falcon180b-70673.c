//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *name;
    int size;
    char *data;
} File;

int main() {
    int count = 0;
    File *files = (File*)malloc(100*sizeof(File));
    char command[100];
    while(1) {
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "scan") == 0) {
            char path[100];
            printf("Enter path to scan: ");
            scanf("%s", path);
            FILE *fp = fopen(path, "rb");
            if(fp == NULL) {
                printf("Error opening file\n");
                continue;
            }
            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            char *buffer = (char*)malloc(size);
            fread(buffer, 1, size, fp);
            fclose(fp);
            for(int i=0; i<count; i++) {
                if(strcmp(files[i].data, buffer) == 0) {
                    printf("File already scanned\n");
                    free(buffer);
                    continue;
                }
            }
            files[count].name = (char*)malloc(strlen(path)+1);
            strcpy(files[count].name, path);
            files[count].size = size;
            files[count].data = buffer;
            count++;
            printf("File scanned successfully\n");
            free(buffer);
        } else if(strcmp(command, "list") == 0) {
            for(int i=0; i<count; i++) {
                printf("%s (%d bytes)\n", files[i].name, files[i].size);
            }
        } else if(strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    for(int i=0; i<count; i++) {
        free(files[i].name);
        free(files[i].data);
    }
    free(files);
    return 0;
}