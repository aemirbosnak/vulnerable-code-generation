//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct entry{
    char date[20];
    char title[50];
    char note[200];
    struct entry *next;
};

typedef struct entry entry;

entry *head=NULL;
entry *tail=NULL;

void add_entry(){
    entry *new_entry=(entry*)malloc(sizeof(entry));
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(new_entry->date,"%02d-%02d-%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    printf("Enter Title: ");
    gets(new_entry->title);
    printf("Enter Note: ");
    gets(new_entry->note);
    new_entry->next=NULL;
    if(head==NULL){
        head=new_entry;
        tail=new_entry;
    }
    else{
        tail->next=new_entry;
        tail=new_entry;
    }
    printf("Entry Added Successfully!\n");
}

void print_entry(entry *e){
    printf("\nDate: %s\n",e->date);
    printf("Title: %s\n",e->title);
    printf("Note: %s\n",e->note);
}

void view_all_entries(){
    if(head==NULL){
        printf("No Entries Found!\n");
        return;
    }
    entry *temp=head;
    int i=1;
    while(temp!=NULL){
        printf("\nEntry %d\n",i++);
        print_entry(temp);
        temp=temp->next;
    }
}

void search_entry(){
    if(head==NULL){
        printf("No Entries Found!\n");
        return;
    }
    char title[50];
    printf("Enter Title to Search: ");
    gets(title);
    entry *temp=head;
    int i=0;
    while(temp!=NULL){
        if(strcmp(temp->title,title)==0){
            print_entry(temp);
            i++;
        }
        temp=temp->next;
    }
    if(i==0){
        printf("No Entries Found with Title \"%s\"!\n",title);
    }
}

void delete_all_entries(){
    if(head==NULL){
        printf("No Entries Found!\n");
        return;
    }
    entry *temp=head;
    while(temp!=NULL){
        head=temp->next;
        free(temp);
        temp=head;
    }
    printf("All Entries Deleted!\n");
}

void delete_entry(){
    if(head==NULL){
        printf("No Entries Found!\n");
        return;
    }
    char title[50];
    printf("Enter Title to Delete: ");
    gets(title);
    entry *temp=head, *prev;
    int i=0;
    while(temp!=NULL){
        if(strcmp(temp->title,title)==0){
            if(temp==head){
                head=temp->next;
                free(temp);
            }
            else if(temp==tail){
                tail=prev;
                prev->next=NULL;
                free(temp);
            }
            else{
                prev->next=temp->next;
                free(temp);
            }
            printf("Entry Deleted Successfully!\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("No Entries Found with Title \"%s\"!\n",title);
}

void menu(){
    printf("\nDigital Diary Menu\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete All Entries\n");
    printf("5. Delete Entry\n");
    printf("6. Exit\n");
    printf("Enter Choice: ");
}

int main(){
    int choice;
    do{
        menu();
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                add_entry();
                break;
            case 2:
                view_all_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_all_entries();
                break;
            case 5:
                delete_entry();
                break;
            case 6:
                printf("Exiting Digital Diary...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }while(choice!=6);
    return 0;
}