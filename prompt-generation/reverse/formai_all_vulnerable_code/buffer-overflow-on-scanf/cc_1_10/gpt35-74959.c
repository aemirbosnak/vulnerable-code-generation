//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now); //get current time
    
    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter a year to travel to: ");
    int year;
    scanf("%d", &year);
    
    if (year < 1900 || year > tm_now->tm_year+1900){
        printf("Invalid year entered. You can only travel to a year between 1900 and %d\n", tm_now->tm_year+1900);
        exit(0);
    }
    printf("\nTravelling to the year %d...\n", year);
    sleep(2);
    
    int diff_year = year - (tm_now->tm_year+1900);
    printf("Welcome to the year %d. It's %d years in the %s.\n", year, abs(diff_year), (diff_year>0)?"future":"past");
    
    if(diff_year>0){ //travel to future
        char *msg1 = "The future is looking bright!";
        char *msg2 = "Oh no, it's the apocalypse!";
        char *msg3 = "Flying cars everywhere!!";
        srand(time(NULL));
        int rand_num = rand()%3;
        if(rand_num==0){
            printf("%s\n", msg1);
        }else if(rand_num==1){
            printf("%s\n", msg2);
        }else{
            printf("%s\n", msg3);
        }
    }else{ //travel to past
        char *msg1 = "You've just missed the Industrial Revolution.";
        char *msg2 = "This looks like the perfect place for some medieval adventure.";
        char *msg3 = "Gather around, people, it's time to watch some gladiators in action!";
        srand(time(NULL));
        int rand_num = rand()%3;
        if(rand_num==0){
            printf("%s\n", msg1);
        }else if(rand_num==1){
            printf("%s\n", msg2);
        }else{
            printf("%s\n", msg3);
        }
    }
    
    return 0;
}