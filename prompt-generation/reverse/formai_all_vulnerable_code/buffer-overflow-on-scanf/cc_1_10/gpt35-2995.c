//FormAI DATASET v1.0 Category: Email Client ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Define the email structure*/
typedef struct email {
    char from[100];
    char to[100];
    char subject[100];
    char body[500];
} Email;

/*Function prototypes*/
void readEmail(Email *e);
void displayEmail(Email *e);
void recursiveEmailClient(int index, int count, Email *e);

int main() {
    /*Initialize the email array*/
    Email emails[10];

    /*Read 10 emails*/
    int i;
    for(i=0; i<10; i++) {
        readEmail(&emails[i]);
    }

    /*Call the recursive email client function*/
    recursiveEmailClient(0, 10, emails);

    return 0;
}

/*Function to read an email*/
void readEmail(Email *e) {
    printf("Enter email details:\n\n");
    printf("From: ");
    scanf("%s", e->from);
    printf("To: ");
    scanf("%s", e->to);
    printf("Subject: ");
    scanf("%s", e->subject);
    printf("Body: ");
    scanf("%s", e->body);
    printf("\n\n");
}

/*Function to display an email*/
void displayEmail(Email *e) {
    printf("From: %s\n", e->from);
    printf("To: %s\n", e->to);
    printf("Subject: %s\n", e->subject);
    printf("Body: %s\n", e->body);
    printf("\n\n");
}

/*Recursive email client function*/
void recursiveEmailClient(int index, int count, Email *e) {
    /*Base case: stop recursion when index equals count*/
    if(index == count) {
        return;
    }
    /*Recursive case: display email at current index,
    ask user if they want to proceed to next email*/
    printf("Email %d:\n\n", index+1);
    displayEmail(&e[index]);
    char choice[3];
    printf("Do you want to read the next email? (y/n): ");
    scanf("%s", choice);
    if(strcmp(choice, "y") == 0) {
        recursiveEmailClient(index+1, count, e);
    }
    else if(strcmp(choice, "n") == 0) {
        printf("\n\nExiting email client...\n\n");
        exit(0);
    }
    else {
        printf("\n\nInvalid choice! Exiting email client...\n\n");
        exit(-1);
    }
}