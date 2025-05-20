//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct meeting {
    char name[50];
    int duration; // in minutes
    int start_time; // in minutes past midnight
};

struct calendar {
    struct meeting meetings[10];
    int num_meetings;
};

void print_meeting(struct meeting m) {
    printf("%s: %d minutes, starting at %02d:%02d\n", m.name, m.duration, m.start_time/60, m.start_time%60);
}

void print_calendar(struct calendar c) {
    printf("Calendar:\n");
    for(int i=0; i<c.num_meetings; i++) {
        print_meeting(c.meetings[i]);
    }
}

void schedule_meeting(struct calendar* c) {
    struct meeting new_meeting;
    printf("Enter meeting name: ");
    scanf("%s", new_meeting.name);
    printf("Enter meeting duration (in minutes): ");
    scanf("%d", &new_meeting.duration);
    printf("Enter meeting start time (in minutes past midnight): ");
    scanf("%d", &new_meeting.start_time);
    
    // Check if new meeting overlaps with existing meetings
    for(int i=0; i<c->num_meetings; i++) {
        int end_time = c->meetings[i].start_time + c->meetings[i].duration;
        if(new_meeting.start_time >= c->meetings[i].start_time && new_meeting.start_time < end_time) {
            printf("Error: new meeting overlaps with %s\n", c->meetings[i].name);
            return;
        }
        if(end_time > new_meeting.start_time && end_time <= new_meeting.start_time + new_meeting.duration) {
            printf("Error: new meeting overlaps with %s\n", c->meetings[i].name);
            return;
        }
    }
    
    // Add new meeting to calendar
    c->meetings[c->num_meetings++] = new_meeting;
    printf("Meeting scheduled successfully!\n");
}

void clear_calendar(struct calendar* c) {
    c->num_meetings = 0; // Reset number of meetings to zero
    printf("Calendar cleared.\n");
}

int main() {
    struct calendar c;
    c.num_meetings = 0; // Initialize number of meetings to zero
    
    while(true) {
        printf("What would you like to do?\n");
        printf("1. Schedule a meeting\n");
        printf("2. View calendar\n");
        printf("3. Clear calendar\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                schedule_meeting(&c);
                break;
            case 2:
                print_calendar(c);
                break;
            case 3:
                clear_calendar(&c);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}