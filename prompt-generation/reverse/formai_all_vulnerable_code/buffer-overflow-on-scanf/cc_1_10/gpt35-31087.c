//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_URL_LENGTH 50
#define MAX_HISTORY_LENGTH 10

char uptime_status[MAX_HISTORY_LENGTH][15];

int check_status(char* url){
    int status = rand()%2;
    if(status == 1)
        strncpy(uptime_status[0], "UP", 2);
    else
        strncpy(uptime_status[0], "DOWN", 4);
    return status;
}

void add_to_history(char* status){
    int i;
    for(i = MAX_HISTORY_LENGTH-1; i > 0; i--){
        strncpy(uptime_status[i], uptime_status[i-1], 15);
    }
    strncpy(uptime_status[0], status, 15);
}

void print_history(){
    int i;
    for(i=0;i<MAX_HISTORY_LENGTH;i++){
        printf("%s ",uptime_status[i]);
    }
    printf("\n");
}

void medieval_print(char* message){
    sleep(1);
    printf("Knight: %s\n", message);
}

int main(){
    char url[MAX_URL_LENGTH];
    int status, choice;
    while(1){
        medieval_print("Hail traveler! What is the URL that you would like me to monitor?");
        scanf("%s", url);
        medieval_print("I will check the status for thee, sire.");
        status = check_status(url);
        if(status == 1){
            medieval_print("Good tidings! This website is UP!");
            add_to_history("UP");
        }
        else{
            medieval_print("Alas! This website is DOWN!");
            add_to_history("DOWN");
        }
        medieval_print("Would you like to see the status history? Enter 1 for yes and 0 for no.");
        scanf("%d", &choice);
        if(choice){
            medieval_print("As you wish, sire. Here are the past 10 statuses:");
            print_history();
        }
        else{
            medieval_print("Very well, sire. Until we meet again.");
        }
        choice = 0;
    }
    return 0;
}