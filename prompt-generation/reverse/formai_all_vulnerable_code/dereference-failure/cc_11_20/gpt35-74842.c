//FormAI DATASET v1.0 Category: File system simulation ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct file {
    char *name;
    char *data;
    int size;
};

struct directory {
    char *name;
    int filecount;
    struct file **files;
};

int main() {
    int dircount = 0, i, j;
    struct directory **directories = (struct directory **)malloc(sizeof(struct directory*));
    directories[dircount] = (struct directory *)malloc(sizeof(struct directory));
    directories[dircount]->name = "root";
    directories[dircount]->filecount = 0;
    directories[dircount]->files = (struct file **)malloc(sizeof(struct file*));
    while(1) {
        char command;
        printf("\nEnter command:\n");
        scanf(" %c", &command);
        if(command == 'q') {
            break;
        } else if(command == 'mkd') {
            char *dirname = (char *)malloc(sizeof(char)*20);
            printf("Enter directory name:\n");
            scanf("%s", dirname);
            dircount++;
            directories = (struct directory **)realloc(directories, (dircount+1)*sizeof(struct directory*));
            directories[dircount] = (struct directory *)malloc(sizeof(struct directory));
            directories[dircount]->name = dirname;
            directories[dircount]->filecount = 0;
            directories[dircount]->files = (struct file **)malloc(sizeof(struct file*));
        } else if(command == 'ls') {
            printf("Directories:\n");
            for(i=0;i<=dircount;i++) {
                printf("%s\n", directories[i]->name);
            }
            printf("Files:\n");
            for(i=0;i<=dircount;i++) {
                for(j=0;j<=directories[i]->filecount;j++) {
                    printf("  %s\n", directories[i]->files[j]->name);
                }
            }
        } else if(command == 'mkf') {
            char *filename = (char *)malloc(sizeof(char)*20);
            printf("Enter file name:\n");
            scanf("%s", filename);
            int dirindex;
            printf("Enter directory index:\n");
            scanf("%d", &dirindex);
            directories[dirindex]->filecount++;
            directories[dirindex]->files = (struct file **)realloc(directories[dirindex]->files, (directories[dirindex]->filecount+1)*sizeof(struct file*));
            directories[dirindex]->files[directories[dirindex]->filecount] = (struct file *)malloc(sizeof(struct file));
            directories[dirindex]->files[directories[dirindex]->filecount]->name = filename;
            directories[dirindex]->files[directories[dirindex]->filecount]->size = 0;
            directories[dirindex]->files[directories[dirindex]->filecount]->data = (char *)malloc(sizeof(char)*100);
        } else if(command == 'write') {
            int dirindex, fileindex;
            printf("Enter directory index:\n");
            scanf("%d", &dirindex);
            printf("Enter file index:\n");
            scanf("%d", &fileindex);
            printf("Enter data to write:\n");
            scanf("%s", directories[dirindex]->files[fileindex]->data);
            directories[dirindex]->files[fileindex]->size = strlen(directories[dirindex]->files[fileindex]->data);
        } else if(command == 'read') {
            int dirindex, fileindex;
            printf("Enter directory index:\n");
            scanf("%d", &dirindex);
            printf("Enter file index:\n");
            scanf("%d", &fileindex);
            printf("Data in file:\n%s\n", directories[dirindex]->files[fileindex]->data);
        }
    }
    return 0;
}