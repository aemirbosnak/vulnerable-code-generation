//FormAI DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct file{
    char *name;
    int size;
    char *type;
    int status;
}file;

int main(){
    int n;
    printf("Enter number of files to recover: ");
    scanf("%d", &n);
    file *files = (file*)malloc(n*sizeof(file));
    for(int i=0;i<n;i++){
        printf("\nFile %d Name: ",i+1);
        files[i].name = (char*)malloc(50*sizeof(char));
        scanf("%s",files[i].name);
        printf("\nFile %d Size: ",i+1);
        scanf("%d",&files[i].size);
        printf("\nFile %d Type: ",i+1);
        files[i].type = (char*)malloc(10*sizeof(char));
        scanf("%s",files[i].type);
        printf("\nFile %d Status(1 for recoverable, 0 for unrecoverable): ",i+1);
        scanf("%d",&files[i].status);
    }

    printf("\nFiles to be recovered:");
    for(int i=0;i<n;i++){
        if(files[i].status == 1){
            printf("\n%s\t%d\t%s", files[i].name, files[i].size, files[i].type);
        }
    }

    printf("\n\nRecovered files:");
    for(int i=0;i<n;i++){
        if(files[i].status == 1){
            printf("\nRecovering %s...", files[i].name);
            // code for recovery process
            printf("Recovered!");
        }
    }

    for(int i=0;i<n;i++){
        free(files[i].name);
        free(files[i].type);
    }
    free(files);
    return 0;
}