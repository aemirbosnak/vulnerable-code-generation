//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include<stdio.h>
#include<stdlib.h>

#define MAX_ATTEMPTS 3
#define LOG_FILE "intrusion_logs.txt"

int main(){

    int count, attempt=0, max_attempts=MAX_ATTEMPTS;
    char password[20];

    FILE * fp;

    fp=fopen(LOG_FILE,"a");

    if(fp==NULL){

        printf("Error: Unable to open file \n");
        exit(1);
    }

    printf("-----INTRUSION DETECTION SYSTEM----- \n");

    printf("Please enter your password: \n");

    while(attempt<MAX_ATTEMPTS){

        scanf("%s",password);

        if(strcmp(password,"password123")==0){

            printf("You are logged in successfully \n");
            fprintf(fp,"Successful login attempt \n");
            break;

        }else{

            printf("Invalid Password! Please try again \n");
            attempt++;
            fprintf(fp,"Failed login attempt \n");

        }
    }
    
    if(attempt==max_attempts){

        printf("Maximum login attempts reached! \n");

        //Send email to notify admin
        system("mail -s 'Intrusion Detected!' admin@example.com < /dev/null");

        //Shutdown system
        system("shutdown now");

        fprintf(fp,"Max login attempts reached \n");       

    }
    fclose(fp);
    return 0;
}