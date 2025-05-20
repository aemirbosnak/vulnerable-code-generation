//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define URL_LENGTH 200

bool isWebsiteUp(char url[]);

int main(){
    
    char url[URL_LENGTH];
    printf("Enter website URL: ");
    scanf("%s", url);

    while(true){

        if(isWebsiteUp(url)){
            printf("Website is up!\n");
        }else{
            printf("Website is down!\n");
        }

        sleep(30); // Sleep for 30 seconds

    }

    return 0;
}

// Returns true if the website is up, false otherwise
bool isWebsiteUp(char url[]){
    char command[URL_LENGTH + 20] = "ping -c 1 ";
    strcat(command, url);

    // Execute command and save output to a temporary file
    system(strcat(command, " > temp.txt"));

    // Open the temporary file in read mode
    FILE* temp_file = fopen("temp.txt", "r");

    // Read the file to check if the website is up
    char temp_char = fgetc(temp_file);
    bool is_up = false;

    while(temp_char != EOF){
        if(temp_char == '1'){
            is_up = true;
            break;
        }

        temp_char = fgetc(temp_file);
    }

    fclose(temp_file);
    system("rm temp.txt"); // Remove the temporary file

    return is_up;
}