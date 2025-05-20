//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int csum(char message[]);
// function declaration for computing the checksum


int main(){

    char message[100];
    int checksum, total_checksum;

    printf("Enter the message to compute checksum:\n");
    fgets(message, 100, stdin); // get input from user

    // remove the newline character from the string generated using fgets
    if(message[strlen(message)-1] == '\n')
        message[strlen(message)-1] = '\0';

    checksum = csum(message); // calling csum function
    printf("Checksum (message): %d\n", checksum);

    total_checksum = checksum;
    printf("Do you want to add another message? (1 for Yes/2 for No):\n");
    int ans;
    scanf("%d", &ans);

    while(ans == 1){
        getchar(); // flush newline character from previous input
        printf("Enter the message to compute checksum:\n");
        fgets(message, 100, stdin); // get input from user

        // remove the newline character from the string generated using fgets
        if(message[strlen(message)-1] == '\n')
            message[strlen(message)-1] = '\0';

        checksum = csum(message); // calling csum function
        printf("Checksum (message): %d\n", checksum);

        total_checksum += checksum; // accumulate checksum for multiple messages

        printf("Do you want to add another message? (1 for Yes/2 for No):\n");
        scanf("%d", &ans);
    }

    printf("Total Checksum: %d\n", total_checksum);

    return 0;
}

// function to compute checksum of a string
int csum(char message[]){
    int i = 0;
    int length = strlen(message);
    int sum = 0;

    while(i < length){

        // adding ASCII value of each character
        sum += (int)message[i];

        // moving to next character
        i += 1;
    }

    return sum;
}