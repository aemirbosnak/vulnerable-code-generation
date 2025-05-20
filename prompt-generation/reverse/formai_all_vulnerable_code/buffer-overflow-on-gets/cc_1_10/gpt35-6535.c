//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Name: CyberCafe Billing System
 * Language: C
 * Author: XYZ
 * Date: DD/MM/YYYY
 * Description: This program tracks the usage of CyberCafe computers and calculates billing based on time used.
*/

// Defining constant rates
#define RATE_PER_HOUR 50
#define RATE_PER_MINUTE 1

// Function to calculate total bill
float calcBill(int hours, int minutes) {
    float bill;
    // Calculating total time in minutes
    int total_minutes = (hours * 60) + minutes;
    // Calculating bill
    if(total_minutes < 60) {
        bill = total_minutes * RATE_PER_MINUTE;
    } else {
        int hours_used = total_minutes / 60;
        int minutes_used = total_minutes % 60;
        bill = (hours_used * RATE_PER_HOUR) + (minutes_used * RATE_PER_MINUTE);
    }
    return bill;
}

int main() {
    int hrs, mins, choice;
    char name[30];
    float bill;
    // Displaying Welcome Message
    printf("\n\tWelcome to Cyber Cafe Billing System!\n");
    // Taking Customer Name
    printf("\nEnter your name: ");
    fflush(stdin);
    gets(name);
    // Taking Usage Details
    printf("\n\tPlease select your usage time:\n\t1. Less than 1 Hour.\n\t2. More than 1 Hour.\n\nEnter your choice: ");
    scanf("%d", &choice);
    // Validating Choice Input
    if(choice!=1 && choice!=2) {
        printf("\n\tInvalid choice! Please try again.");
        exit(0);
    }
    // Taking Usage Time Input
    if(choice == 1) {
        printf("\nEnter the number of minutes used: ");
        scanf("%d", &mins);
        bill = calcBill(0, mins);
    } else {
        printf("\nEnter the number of hours used: ");
        scanf("%d", &hrs);
        printf("\nEnter the number of minutes used: ");
        scanf("%d", &mins);
        bill = calcBill(hrs, mins);
    }
    // Displaying Bill
    printf("\n\n\t\t---Billing Details---\n");
    printf("\n\tName: %s", name);
    printf("\n\tTotal Time Used: %d hours %d minutes", hrs, mins);
    printf("\n\tTotal Bill Amount: %.2f Rs.", bill);
    printf("\n\nThank you for using Cyber Cafe. Have a nice day!");
    return 0;
}