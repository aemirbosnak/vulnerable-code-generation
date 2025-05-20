//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER_NUM 10
#define MAX_EVENT_NUM 100
#define MAX_EVENT_NAME_LEN 50
#define MAX_EVENT_DURATION 24*60*60 // 1 day

typedef struct {
    char name[MAX_EVENT_NAME_LEN];
    int duration;
} Event;

typedef struct {
    char name[MAX_USER_NUM];
    int age;
    int gender;
} User;

void print_menu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add user\n");
    printf("2. Add event\n");
    printf("3. Start event\n");
    printf("4. End event\n");
    printf("5. View event history\n");
    printf("6. View user history\n");
    printf("7. Quit\n");
}

int main() {
    int choice, user_num = 0;
    char user_name[MAX_USER_NUM][MAX_USER_NUM];
    int user_age[MAX_USER_NUM];
    int user_gender[MAX_USER_NUM];
    Event event_list[MAX_EVENT_NUM];
    int event_num = 0;

    printf("Welcome to Fitness Tracker!\n");
    while(1) {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(user_num >= MAX_USER_NUM) {
                    printf("Maximum number of users reached.\n");
                } else {
                    printf("Enter user name: ");
                    scanf("%s", user_name[user_num]);
                    printf("Enter age: ");
                    scanf("%d", &user_age[user_num]);
                    printf("Enter gender (0 for male, 1 for female): ");
                    scanf("%d", &user_gender[user_num]);
                    user_num++;
                }
                break;
            case 2:
                if(event_num >= MAX_EVENT_NUM) {
                    printf("Maximum number of events reached.\n");
                } else {
                    printf("Enter event name: ");
                    scanf("%s", event_list[event_num].name);
                    printf("Enter duration (in seconds): ");
                    scanf("%d", &event_list[event_num].duration);
                    event_num++;
                }
                break;
            case 3:
                printf("Enter event name: ");
                scanf("%s", event_list[0].name);
                printf("Enter duration (in seconds): ");
                scanf("%d", &event_list[0].duration);
                printf("Event started!\n");
                break;
            case 4:
                printf("Enter event name: ");
                scanf("%s", event_list[0].name);
                printf("Event ended!\n");
                break;
            case 5:
                printf("Event history:\n");
                for(int i=0; i<event_num; i++) {
                    printf("%s - %d seconds\n", event_list[i].name, event_list[i].duration);
                }
                break;
            case 6:
                printf("User history:\n");
                for(int i=0; i<user_num; i++) {
                    printf("%s - Age: %d - Gender: %d\n", user_name[i], user_age[i], user_gender[i]);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}