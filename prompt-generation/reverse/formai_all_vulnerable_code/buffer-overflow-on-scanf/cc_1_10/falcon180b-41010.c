//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 5000

struct entry{
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry *entries, int num_entries, char *date, char *time, char *content){
    if(num_entries >= MAX_ENTRIES){
        printf("Diary is full. Please delete an entry to add a new one.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].content, content);
    num_entries++;
}

void delete_entry(struct entry *entries, int num_entries){
    if(num_entries == 0){
        printf("Diary is empty.\n");
        return;
    }
    num_entries--;
}

void print_entries(struct entry *entries, int num_entries){
    printf("Diary Entries:\n");
    for(int i=0; i<num_entries; i++){
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

void main(){
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    while(1){
        printf("1. Add Entry\n2. Delete Entry\n3. Print Entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                char date[20];
                char time[10];
                char content[MAX_ENTRY_LENGTH];
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", date);
                printf("Enter time (hh:mm:ss): ");
                scanf("%s", time);
                printf("Enter content:\n");
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                content[strcspn(content, "\n")] = '\0'; // remove newline character
                add_entry(diary, num_entries, date, time, content);
                break;
            }
            case 2:{
                delete_entry(diary, num_entries);
                break;
            }
            case 3:{
                print_entries(diary, num_entries);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
}