//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int main() {
    File file;
    char command[50];
    int i = 0;
    
    printf("Welcome to the Shape Shifting File System!\n");
    
    while(1) {
        printf("Command: ");
        scanf("%s", command);
        
        if(strcasecmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", file.name);
            strcat(file.name, ".dat");
            printf("Enter file size: ");
            scanf("%d", &file.size);
            for(i = 0; i < file.size; i++) {
                printf("Enter data for byte %d: ", i);
                scanf("%c", &file.data[i]);
            }
            printf("File created successfully!\n");
        }
        else if(strcasecmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", file.name);
            FILE *fp = fopen(file.name, "rb");
            if(fp == NULL) {
                printf("File not found!\n");
            }
            else {
                while(!feof(fp)) {
                    printf("%c", fgetc(fp));
                }
                fclose(fp);
                printf("\n");
            }
        }
        else if(strcasecmp(command, "write") == 0) {
            printf("Enter file name: ");
            scanf("%s", file.name);
            FILE *fp = fopen(file.name, "wb");
            if(fp == NULL) {
                printf("File not found!\n");
            }
            else {
                for(i = 0; i < file.size; i++) {
                    fputc(file.data[i], fp);
                }
                fclose(fp);
                printf("File written successfully!\n");
            }
        }
        else if(strcasecmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", file.name);
            int res = remove(file.name);
            if(res!= 0) {
                printf("File not found!\n");
            }
            else {
                printf("File deleted successfully!\n");
            }
        }
        else if(strcasecmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command!\n");
        }
    }
    
    return 0;
}