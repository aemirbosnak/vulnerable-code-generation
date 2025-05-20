//FormAI DATASET v1.0 Category: Data validation ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the surprise C Data Validation program!\n");
    
    // Prompt user to enter an integer between 1 and 100
    int num;
    do {
        printf("Please enter an integer between 1 and 100: ");
        scanf("%d", &num);
        if (num < 1 || num > 100) {
            printf("Whoa! That value is out of range.\n");
            printf("Try entering a value between 1 and 100 this time.\n");
        }
    } while (num < 1 || num > 100);
    
    printf("You entered: %d\n", num);
    printf("Great job! Now let's move onto validating a character.\n");
    
    // Prompt user to enter a lowercase letter
    char letter;
    do {
        printf("Please enter a lowercase letter: ");
        scanf(" %c", &letter);
        if (letter < 'a' || letter > 'z') {
            printf("Hold on there, cowboy! That's not a lowercase letter.\n");
            printf("Try entering a lowercase letter this time.\n");
        }
    } while (letter < 'a' || letter > 'z');
    
    printf("You entered: %c\n", letter);
    printf("Fantastic! Let's see if you can input a valid float next.\n");
    
    // Prompt user to enter a float between -1000 and 1000
    float fnum;
    do {
        printf("Please enter a float between -1000 and 1000: ");
        scanf("%f", &fnum);
        if (fnum < -1000 || fnum > 1000) {
            printf("Whoops! That's not a valid float within the range of -1000 to 1000.\n");
            printf("Try entering a value within the range this time.\n");
        }
    } while (fnum < -1000 || fnum > 1000);
    
    printf("You entered: %f\n", fnum);
    printf("Amazing! Finally, let's check if you can enter a valid email address.\n");
    
    // Prompt user to enter an email address
    char email[100];
    int i, at = 0, dot = 0;
    do {
        printf("Please enter an email address: ");
        scanf("%s", email);
        for (i = 0; email[i] != '\0'; i++) {
            if (email[i] == '@') {
                at++;
            }
            if (email[i] == '.') {
                dot++;
            }
        }
        if (at != 1 || dot < 1) {
            printf("Oops! That doesn't look like a valid email address.\n");
            printf("Try entering a valid email address this time.\n");
        }
    } while (at != 1 || dot < 1);
    
    printf("You entered: %s\n", email);
    printf("Congratulations, you've successfully validated all the data types!\n");
    printf("Thanks for using this program. We hope to see you soon!\n");
    
    return 0;
}