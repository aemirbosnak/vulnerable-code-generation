//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Medival-style Automated Fortune Teller Program
    
    printf("Welcome, traveler!\n\n");
    printf("What do you seek?\n");
    printf("1. Love\n");
    printf("2. Wealth\n");
    printf("3. Adventure\n");
    printf("4. Fame\n\n");
    
    int answer;
    scanf("%d", &answer);
    
    switch(answer) {
        case 1:
            printf("\nAh, love! A tricky business indeed.\n");
            break;
        case 2:
            printf("\nWealth brings power, but it can also bring ruin.\n");
            break;
        case 3:
            printf("\nAdventure awaits! But be wary of what dangers it brings.\n");
            break;
        case 4:
            printf("\nFame can bring admiration, but it can also invite jealousy.\n");
            break;
        default:
            printf("\nI'm sorry, I don't understand. Please enter a valid option.\n");
            return 0;
    }
    
    printf("\nLet me peer into the crystal ball...\n");
    
    srand(time(NULL));
    int fortune = rand() % 10 + 1; // generate random number between 1 and 10
    
    switch(fortune) {
        case 1:
            printf("\nThe stars foretell great prosperity in your future!\n");
            break;
        case 2:
            printf("\nHm, the spirits are unclear. Your future is hazy.\n");
            break;
        case 3:
            printf("\nBeware! A great danger lurks in your future.\n");
            break;
        case 4:
            printf("\nYour future holds great success and achievement!\n");
            break;
        case 5:
            printf("\nA dark cloud looms over your future. Be cautious.\n");
            break;
        case 6:
            printf("\nYour future holds many exciting adventures! Embrace them.\n");
            break;
        case 7:
            printf("\nThe future is not set in stone. You have the power to change it.\n");
            break;
        case 8:
            printf("\nGood fortune and luck will follow you wherever you go.\n");
            break;
        case 9:
            printf("\nBe wary of those who seek to harm you. They are near.\n");
            break;
        case 10:
            printf("\nYour future is bright and full of promise. Keep striving towards your goals.\n");
    }
    
    printf("\nThank you for visiting. Safe travels!\n");    
    
    return 0;
}