//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct log {
    char date[20];
    char time[20];
    char message[100];
};

int main() {
    int choice, count = 0;
    struct log book[100]; // maximum entries allowed is 100
    time_t now;
    struct tm *t;
    
    do {
        printf("\n\n\t\t-Digital Diary-\n\n");
        printf("\t\t1. Add entry\n");
        printf("\t\t2. View all entries\n");
        printf("\t\t3. Exit\n\n");
        printf("\t\tEnter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                now = time(NULL);
                t = localtime(&now);
                printf("\nCurrent Date: %02d/%02d/%04d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
                printf("Current Time: %02d:%02d\n", t->tm_hour, t->tm_min);
                printf("\nEnter your message (maximum 100 characters):\n\n");
                fflush(stdin);
                gets(book[count].message);
                strncpy(book[count].date, asctime(t), 10);
                strncpy(book[count].time, asctime(t)+11, 5);
                count++;
                printf("\nEntry added successfully!\n");
                break;
            case 2:
                printf("\nLog entry:\n\n");
                for(int i=0; i<count; i++) {
                    printf("Date: %s", book[i].date);
                    printf("Time: %s", book[i].time);
                    printf("Message: %s\n\n", book[i].message);
                }
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please enter 1, 2 or 3.\n");
        }
    } while(choice!=3);
    
    return 0;
}