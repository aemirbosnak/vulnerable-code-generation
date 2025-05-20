//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Function to encrypt the time-travel code
char* cryptic(char* code){
    int i, key = 7;
    char *encrypted_code = (char*)malloc(sizeof(char) * strlen(code));
    for(i=0;i<strlen(code);i++){
        encrypted_code[i] = code[i] + key;
        key = (key + 1) % 9;
    }
    encrypted_code[strlen(code)] = '\0';
    return encrypted_code;
}

//Function to decrypt the time-travel code
char* de_cryptic(char* en_code){
    int i, key = 7;
    char *decrypted_code = (char*)malloc(sizeof(char) * strlen(en_code));
    for(i=0;i<strlen(en_code);i++){
        decrypted_code[i] = en_code[i] - key;
        key = (key + 1) % 9;
    }
    decrypted_code[strlen(en_code)] = '\0';
    return decrypted_code;
}

//Main function to time-travel simulator
int main(){
    time_t now;
    struct tm *tm_now;
    int options, year, month, day, hour, minute, sec, i, flag = 0;
    char time_travel[100], *encrypted_time, *decrypted_time;
    
    //Get the current time
    now = time(NULL);
    tm_now = localtime(&now);
    printf("Welcome to Time Travel Simulator!\n");
    printf("Current date & Time: %s", asctime(tm_now));
    printf("1. Travel to past\n2. Travel to future\nEnter your choice (1 or 2): ");
    scanf("%d", &options);
    
    //If user chooses to travel to past
    if(options == 1){
        printf("Enter the date & time you wish to travel (in the format yyyy mm dd hh mm ss): ");
        scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &sec);
        
        //Check if the entered date & time is valid and not later than current date & time
        if(year > tm_now->tm_year + 1900 || (year == tm_now->tm_year + 1900 && month > tm_now->tm_mon + 1) || (year == tm_now->tm_year + 1900 && month == tm_now->tm_mon + 1 && day > tm_now->tm_mday) || (year == tm_now->tm_year + 1900 && month == tm_now->tm_mon + 1 && day == tm_now->tm_mday && hour > tm_now->tm_hour) || (year == tm_now->tm_year + 1900 && month == tm_now->tm_mon + 1 && day == tm_now->tm_mday && hour == tm_now->tm_hour && minute > tm_now->tm_min) || (year == tm_now->tm_year + 1900 && month == tm_now->tm_mon + 1 && day == tm_now->tm_mday && hour == tm_now->tm_hour && minute == tm_now->tm_min && sec > tm_now->tm_sec)){
            printf("Invalid date & time entered. Please try again.\n");
            flag = 1;
        }
        
        //If the entered date & time is valid, calculate the difference in seconds between current and entered date & time
        if(flag == 0){
            tm_now->tm_year = year - 1900;
            tm_now->tm_mon = month - 1;
            tm_now->tm_mday = day;
            tm_now->tm_hour = hour;
            tm_now->tm_min = minute;
            tm_now->tm_sec = sec;
            now = mktime(tm_now);
            printf("Travelling to past...\n");
            while(difftime(now, time(NULL)) > 0);
            printf("You have successfully time-traveled to %s\n", asctime(tm_now));
        }
    }
    
    //If user chooses to travel to future
    else if(options == 2){
        printf("Enter the time duration for which you wish to travel (in the format hh mm ss): ");
        scanf("%d %d %d", &hour, &minute, &sec);
        
        //Calculate the future time
        tm_now->tm_hour += hour;
        tm_now->tm_min += minute;
        tm_now->tm_sec += sec;
        now = mktime(tm_now);
        printf("Travelling to future...\n");
        while(difftime(now, time(NULL)) > 0);
        printf("You have successfully time-traveled to %s\n", asctime(tm_now));
    }
    
    //If user enters invalid option
    else{
        printf("Invalid option selected. Please try again.\n");
    }
    
    printf("Do you want to remember this time-travel trip code for future use? (yes/no): ");
    scanf("%s", time_travel);
    
    //If user chooses to remember the time-travel trip code
    if(strcmp(time_travel, "yes") == 0){
        printf("Your time-travel trip code is: ");
        for(i=0;i<strlen(asctime(tm_now));i++){
            if(asctime(tm_now)[i] != ' ' && asctime(tm_now)[i] != '\n')
                printf("%c",asctime(tm_now)[i]);
        }
        encrypted_time = cryptic(asctime(tm_now));
        printf("\nYour crypted time-travel trip code is: %s\n", encrypted_time);
    }
    
    //If user chooses not to remember the time-travel trip code
    else if(strcmp(time_travel, "no") == 0){
        printf("Thank you for using Time Travel Simulator!\n");
    }
    
    //If user enters invalid option
    else{
        printf("Invalid option selected. Thank you for using Time Travel Simulator!\n");
    }
    
    decrypted_time = de_cryptic(encrypted_time);
    printf("Your decrypted time-travel trip code is: %s\n", decrypted_time);
    
    return 0;
}