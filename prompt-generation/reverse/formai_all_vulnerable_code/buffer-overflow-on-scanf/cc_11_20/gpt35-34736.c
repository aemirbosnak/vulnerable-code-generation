//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, lucky_number, random_number;
    char answer;
    
    printf("Hello there! I am your automated fortune teller. \n");
    printf("What is your name? ");
    scanf("%s", name);
    
    printf("Hi %s, please tell me your age: ", name);
    scanf("%d", &age);
    
    printf("Now, tell me your lucky number: ");
    scanf("%d", &lucky_number);
    
    printf("Great! Let's get started.\n\n");
    
    printf("Think of a question that you want answered and press any key when ready.\n");
    getchar(); // flush buffer
    
    srand(time(NULL)); // set seed for random number
    
    random_number = rand() % 10; // generate random number between 0 and 9
    
    if(random_number == 0) {
        printf("The stars are aligned in your favor, %s. You will receive some unexpected good news soon. Trust your instincts and take action when the time is right.\n", name);
    } else if(random_number == 1) {
        printf("You are on the path to success, %s. Keep putting in the hard work and stay motivated; the rewards will come.\n", name);
    } else if(random_number == 2) {
        printf("Beware of a jealous friend, %s. Someone close to you may be trying to sabotage your efforts. Stay alert and trust your gut.\n", name);
    } else if(random_number == 3) {
        printf("A new opportunity is on the horizon, %s. Keep your eyes open and be ready to seize the moment when it arises.\n", name);
    } else if(random_number == 4) {
        printf("You may be feeling stuck in your current situation, %s. Take a step back and try to view the problem from a different perspective. The solution may be closer than you think.\n", name);
    } else if(random_number == 5) {
        printf("The journey may be tough, %s, but the destination is worth it. Keep pushing forward, even when the going gets rough.\n", name);
    } else if(random_number == 6) {
        printf("A major change is coming your way, %s. Embrace it with open arms and stay positive. This could be the beginning of a new and exciting chapter in your life.\n", name);
    } else if(random_number == 7) {
        printf("Your loved ones are the key to your success, %s. Lean on the support and guidance of those closest to you when you need it most.\n", name);
    } else if(random_number == 8) {
        printf("You may be feeling unsure of yourself, %s, but have faith in your abilities. You are capable of achieving anything you set your mind to.\n", name);
    } else {
        printf("It's time to take a leap of faith, %s. Trust yourself and your instincts and take the plunge. You won't regret it.\n", name);
    }
    
    printf("\nWould you like another reading? (Y/N): ");
    scanf(" %c", &answer);
    
    if(answer == 'Y' || answer == 'y') {
        printf("\nGreat! Let's try again.\n\n");
        main(); // restart the program for another reading
    } else {
        printf("\nThank you for using the Automated Fortune Teller. Good luck in all your endeavors, %s!\n", name);
    }
    
    return 0;
}