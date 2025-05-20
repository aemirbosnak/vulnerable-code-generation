//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20], response;
    int birthday, lucky_number, fortune_number;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! \n", name);

    printf("Please enter your birthday (mmddyyyy): ");
    scanf("%d", &birthday);
    printf("\n");

    printf("Please enter your lucky number: ");
    scanf("%d", &lucky_number);
    printf("\n");

    printf("Thank you for providing your information.\n");
    printf("Press any key to get your fortune. \n");
    response = getchar();

    srand(time(NULL));
    fortune_number = rand() % 10 + 1;

    switch (fortune_number) {
        case 1:
            printf("Your lucky number is %d, and your fortune is: A bright future lies ahead for you. Keep your head up and stay positive. \n", lucky_number);
            break;
        case 2:
            printf("Your lucky number is %d, and your fortune is: You will soon come into good fortune. Keep your eyes open for opportunities. \n", lucky_number);
            break;
        case 3:
            printf("Your lucky number is %d, and your fortune is: You will face a great challenge in the near future. Stay strong and persevere. \n", lucky_number);
            break;
        case 4:
            printf("Your lucky number is %d, and your fortune is: Romance is in the air. You may soon meet your soulmate. \n", lucky_number);
            break;
        case 5:
            printf("Your lucky number is %d, and your fortune is: Financial stability is on the horizon. Keep working hard and your efforts will pay off. \n", lucky_number);
            break;
        case 6:
            printf("Your lucky number is %d, and your fortune is: Trouble lies ahead. Be wary of those around you and keep your guard up. \n", lucky_number);
            break;
        case 7:
            printf("Your lucky number is %d, and your fortune is: A long journey is in your future. Be open to new experiences and embrace change. \n", lucky_number);
            break;
        case 8:
            printf("Your lucky number is %d, and your fortune is: You will soon be rewarded for your hard work. Keep pushing and never give up. \n", lucky_number);
            break;
        case 9:
            printf("Your lucky number is %d, and your fortune is: A minor setback is in your future. Don't let it discourage you. Keep pushing forward. \n", lucky_number);
            break;
        case 10:
            printf("Your lucky number is %d, and your fortune is: Your creativity will lead to great success in the near future. Keep creating and innovating! \n", lucky_number);
            break;
        default:
            printf("Error: Could not generate fortune. Please try again later.");
    }
    return 0;
}