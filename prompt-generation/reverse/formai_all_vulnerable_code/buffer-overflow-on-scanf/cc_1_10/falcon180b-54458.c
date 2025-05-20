//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_EVENTS 100

struct event{
    char *description;
    time_t timestamp;
};

struct event events[MAX_EVENTS];
int num_events = 0;

void register_event(char *description){
    if(num_events >= MAX_EVENTS){
        printf("Error: Maximum number of events reached.\n");
        return;
    }
    events[num_events].description = description;
    events[num_events].timestamp = time(NULL);
    num_events++;
}

void display_events(){
    printf("Event Log:\n");
    for(int i=0; i<num_events; i++){
        printf("%s - %s\n", events[i].description, ctime(&events[i].timestamp));
    }
}

void time_travel(time_t target_time){
    char input[100];
    printf("Enter your name: ");
    scanf("%s", input);
    printf("Welcome to the Time Travel Simulator, %s!\n", input);
    printf("You have been transported to the year %d.\n", (int)target_time);
    display_events();
    printf("Press Enter to return to the present...\n");
    getchar();
}

int main(){
    char input[100];
    printf("Welcome to the Time Travel Simulator!\n");
    while(1){
        printf("Enter your desired destination (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        struct tm target_time;
        strptime(input, "%Y-%m-%d %H:%M:%S", &target_time);
        time_t timestamp = mktime(&target_time);
        time_travel(timestamp);
    }
    return 0;
}