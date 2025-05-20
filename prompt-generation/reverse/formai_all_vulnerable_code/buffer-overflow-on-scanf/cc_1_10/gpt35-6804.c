//FormAI DATASET v1.0 Category: Email Client ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LIMIT 1000

//Function to validate Email Address
int validateEmail(char email[]) {
    int i, at_flag = 0, dot_flag = 0;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_flag = 1;
        }
        if (email[i] == '.') {
            dot_flag = 1;
        }
    }
    if (at_flag == 1 && dot_flag == 1) {
        return 1;
    } else {
        return 0;
    }
}

//Function to write email to file
void writeEmailToFile(char to_email[], char subject[], char message[]) {
    char filename[MAX_LIMIT];
    FILE *fp;
    printf("\nEnter file name to save email (eg: email.txt): ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    fprintf(fp, "To: %s\n", to_email);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: %s\n", message);
    fclose(fp);
    printf("\nEmail saved to file successfully!\n");
}

//Main function
int main () {
    char to_email[MAX_LIMIT], subject[MAX_LIMIT], message[MAX_LIMIT];
    printf("\n");
    printf("*************************************************\n");
    printf("*******Welcome to Peaceful Email Client**********\n");
    printf("*************************************************\n");
    printf("\n");
    printf("Enter To Email address: ");
    scanf("%s", to_email);
    if (validateEmail(to_email) == 0) {
        printf("\nInvalid Email Address! Please enter a valid Email Address.\n");
        return 0;
    }
    printf("Enter Email Subject: ");
    scanf(" %[^\n]s", subject);
    printf("Enter Email Message: ");
    scanf(" %[^\n]s", message);
    writeEmailToFile(to_email, subject, message); //calling function to write email to file
    return 0;
}