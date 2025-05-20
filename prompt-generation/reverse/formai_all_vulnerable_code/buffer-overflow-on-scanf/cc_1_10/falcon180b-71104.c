//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SIZE 100

struct Entry{
    char date[11];
    char time[9];
    char content[300];
};

struct Entry diary[SIZE];
int num_entries = 0;

void add_entry(){
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, 11, "%Y-%m-%d", t);
    strftime(diary[num_entries].time, 9, "%H:%M:%S", t);

    printf("Enter your entry:\n");
    fgets(diary[num_entries].content, 300, stdin);

    num_entries++;
}

void view_entries(){
    printf("\nDate & Time\tContent\n");
    for(int i=0; i<num_entries; i++){
        printf("%s %s\t%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entry(){
    char search_date[11];
    char search_time[9];

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", search_date);
    printf("Enter the time (HH:MM:SS): ");
    scanf("%s", search_time);

    for(int i=0; i<num_entries; i++){
        if(strcmp(diary[i].date, search_date) == 0 && strcmp(diary[i].time, search_time) == 0){
            printf("\n%s %s\n%s", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

int main(){
    srand(time(NULL));
    int choice;

    printf("Welcome to Digital Diary!\n");
    printf("1. Add Entry\n2. View Entries\n3. Search Entry\n4. Exit\n");

    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Thank you for using Digital Diary!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    }while(choice!= 4);

    return 0;
}