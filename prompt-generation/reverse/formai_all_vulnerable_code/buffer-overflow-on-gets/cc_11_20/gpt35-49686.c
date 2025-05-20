//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct directory {
    char name[20];
    int size;
    int count;
    struct directory *sub_directory;
    struct file *files;
};

struct file {
    char name[20];
    int size;
    char data[100];
};

int main() {
    struct directory root_dir;
    strcpy(root_dir.name, "root");
    root_dir.size = 0;
    root_dir.count = 0;
    root_dir.sub_directory = NULL;
    root_dir.files = NULL;
    
    int menu_choice;
    do {
        printf("\nFile System Menu\n");
        printf("-------------------\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. List Files and Directories\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        fflush(stdin);

        switch(menu_choice) {
            case 1: {
                char name[20];
                printf("Enter directory name: ");
                scanf("%s", name);
                fflush(stdin);
                int flag=0;
                for(int i=0; i<root_dir.count; i++) {
                    if(!strcmp(root_dir.sub_directory[i].name, name)) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    printf("Directory already exists!\n");
                } else {
                    root_dir.count++;
                    root_dir.sub_directory = (struct directory*)realloc(root_dir.sub_directory, sizeof(struct directory)*root_dir.count);
                    strcpy(root_dir.sub_directory[root_dir.count-1].name, name);
                    root_dir.sub_directory[root_dir.count-1].size = 0;
                    root_dir.sub_directory[root_dir.count-1].count = 0;
                    root_dir.sub_directory[root_dir.count-1].sub_directory = NULL;
                    root_dir.sub_directory[root_dir.count-1].files = NULL;
                    printf("%s directory created successfully!\n",name);
                }
                break;
            }

            case 2: {
                char name[20];
                printf("Enter file name: ");
                scanf("%s", name);
                fflush(stdin);
                int flag=0;
                for(int i=0; i<root_dir.size; i++) {
                    if(!strcmp(root_dir.files[i].name, name)) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    printf("File already exists!\n");
                } else {
                    root_dir.size++;
                    root_dir.files = (struct file*)realloc(root_dir.files, sizeof(struct file)*root_dir.size);
                    strcpy(root_dir.files[root_dir.size-1].name, name);
                    printf("Enter file data: ");
                    gets(root_dir.files[root_dir.size-1].data);
                    root_dir.files[root_dir.size-1].size = strlen(root_dir.files[root_dir.size-1].data);
                    printf("%s file created successfully!\n", name);
                }
                break;
            }

            case 3: {
                printf("\nList of Directories:\n");
                printf("---------------------\n");
                for(int i=0; i<root_dir.count; i++) {
                    printf("%s\n", root_dir.sub_directory[i].name);
                }

                printf("\nList of Files:\n");
                printf("---------------------\n");
                for(int i=0; i<root_dir.size; i++) {
                    printf("%s (%d bytes)\n", root_dir.files[i].name, root_dir.files[i].size);
                }
                break;
            }

            case 4:
                break;

            default:
                printf("Invalid choice. Please try again!\n");
                break;
        }

    } while(menu_choice != 4);

    return 0;
}