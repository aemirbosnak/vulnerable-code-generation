//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gasp! A banking record system? In C? Who would've thought?

// Declare the account structure to hold customer details
typedef struct {
    char name[50];     // Brace yourselves for ridiculously long names!
    long account_number;  // Numbers so big they'll make your head spin!
    double balance;     // Money, money, money... oh yeah!
} account;

// Behold, the mighty account database!
account accounts[1000];   // That's a lot of accounts! We're practically a megabank!

int main() {
    // Wait, what? A banking system without a menu? Impossible!
    printf("Welcome to our exclusive banking system!\n");
    printf("Enter your name, account number, and balance:\n");
    
    // Oh, there it is! The legendary input loop!
    for (int i = 0; i < 1000; i++) {
        scanf("%s %ld %lf", accounts[i].name, &accounts[i].account_number, &accounts[i].balance);
        
        // What's this? A special exit condition? No more accounts? Say it ain't so!
        if (accounts[i].account_number == 0) {
            break;
        }
    }
    
    // Hold your horses! We're not done yet!
    printf("Now, let's perform some banking magic!\n");
    printf("Enter an account number to see its balance:\n");
    
    // Voilà! The account number search extraordinaire!
    long account_number;
    scanf("%ld", &account_number);
    
    // Oops, looks like that account doesn't exist. Better luck next time!
    int found = 0;
    for (int i = 0; i < 1000; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account balance: %.2lf\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Oops! No such account exists. Try again later!\n");
    }
    
    // That's all, folks! Thanks for banking with us!
    printf("Thank you for using our banking system. Have a financially fabulous day!\n");
    return 0;
}