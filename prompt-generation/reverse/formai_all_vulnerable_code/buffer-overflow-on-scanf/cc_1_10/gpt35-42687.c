//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct diary{
    char date[20];
    char notes[100];
};

void create_record(){
    struct diary entry;
    FILE *file;
    char c;
    file = fopen("diary.txt","a+");
    printf("Enter the date in the format dd/mm/yyyy:\n");
    scanf("%s",&entry.date);
    printf("Enter your notes:\n");
    fflush(stdin);
    fgets(entry.notes,sizeof(entry.notes),stdin);
    fprintf(file,"%s\n%s\n",entry.date,entry.notes);
    fclose(file);
}

void search_records(){
    char target[20];
    int flag = 0;
    struct diary entry;
    FILE *file;
    file = fopen("diary.txt","r");
    printf("Enter the date to search in the format dd/mm/yyyy:\n");
    scanf("%s",&target);
    while(fscanf(file,"%s\n%s\n",entry.date,entry.notes)!=EOF){
        if(strcmp(target,entry.date)==0){
            printf("%s\n",entry.notes);
            flag = 1;
        }
    }
    if(flag==0){
        printf("No records found\n");
    }
    fclose(file);
}

int main(){
    int choice,i=1;
    while(i==1){
        printf("*******Digital Diary*******\n");
        printf("1. Create new record\n");
        printf("2. Search a record\n");
        printf("3. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_record();
                break;
            case 2:
                search_records();
                break;
            case 3:
                i=0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}