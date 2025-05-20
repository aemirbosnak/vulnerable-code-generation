//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 20

struct file{
    char name[MAX_FILE_NAME_LENGTH];
    char content[100];
};

struct backup_file{
    struct file backup[MAX_FILES];
    int top;
};

void push(struct backup_file *b,char name[],char content[]){
    if(b->top == MAX_FILES){
        printf("Backup capacity exceeded\n");
        return;
    }
    strcpy(b->backup[b->top].name,name); 
    strcpy(b->backup[b->top].content,content);
    b->top++;
}

void display(struct backup_file b){
    int i;
    printf("\nList of Backup Files:\n");
    for(i=0;i<b.top;i++){
        printf("%s : %s\n",b.backup[i].name,b.backup[i].content);
    }
}

void remove_backup_file(struct backup_file *b,char name[]){
    int i,j,flag = 0;
    for(i=0;i<b->top;i++){
        if(strcmp(b->backup[i].name,name)==0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Backup file with name %s does not exist\n",name);
        return;
    }
    for(j=i;j<b->top-1;j++){
        b->backup[j] = b->backup[j+1];
    }
    b->top--;
    printf("Backup file %s removed successfully!\n",name);
}

int main(){

    struct backup_file b;
    b.top = 0;
    int opt;
    char fname[MAX_FILE_NAME_LENGTH],content[100];
    while(1){
        printf("\nEnter option:\n1. Backup File\n2. Remove Backup File\n3. Display Backup Files\n4. Exit\nOption: ");
        scanf("%d",&opt);
        switch(opt){
            case 1: 
                printf("\nEnter filename (max 20 chars): ");
                scanf("%s",fname);
                printf("Enter file content: ");
                scanf("%s",content);
                push(&b,fname,content);
                printf("\nBackup successful!\n");
                break;
            case 2:
                printf("\nEnter backup file name to delete: ");
                scanf("%s",fname);
                remove_backup_file(&b,fname);
                break;
            case 3:
                display(b);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}