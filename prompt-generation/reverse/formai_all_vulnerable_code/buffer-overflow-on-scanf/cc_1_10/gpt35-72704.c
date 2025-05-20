//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char name[30];
    char feeling[20];
    char response[50];

    printf("Welcome to the Love Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nOh, %s! It's so nice to meet you\n", name);
    printf("How are you feeling today, %s? ", name);
    scanf("%s", feeling);

    printf("\n%s ? That's so good to hear!\n", feeling);
    printf("I hope this adventure will make you feel even better!\n");

    printf("\nYou find yourself standing in front of a beautiful garden.\n");
    printf("Do you want to (1) enter the garden or (2) keep walking?\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nAs you enter the garden, you are greeted with the sweet scent of roses and lilies.\n");
        printf("You walk around the garden, admiring the various flowers and plants.\n");
        printf("As you continue wandering, you come across a small pond with fishes swimming in it\n");

        printf("\nYou notice someone sitting near the pond. It's a person with long hair and a gentle smile\n");
        printf("Do you want to (1) go talk to them or (2) continue walking?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou approach the person and they turn to look at you with kind eyes.\n");
            printf("Deep down, you feel like you have known this person for ages.\n");
            printf("You start to talk and soon realize you have a lot in common.\n");
            printf("You spend the rest of the day with them, enjoying the garden and each other's company\n");

            printf("\nAs the evening draws near, the person turns to you and says\n");
            printf("\"%s, I had a wonderful time with you today. Would you like to go on a date with me?\"\n", name);
            printf("Do you (1) say yes or (2) decline?\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\n\"Yes! I would love to go on a date with you\", you respond.\n");
                printf("The person's face lights up with a smile, and they take your hand.\n");
                printf("You leave the garden, feeling happy and excited for the date.\n");
                printf("The end!\n");
                return 0;
            } else {
                printf("\n\"I'm sorry, I don't think it would work out\", you respond.\n");
                printf("The person looks a little disappointed, but they still smile.\n");
                printf("\"That's alright, I understand. It was still great spending time with you\", they say.\n");
                printf("You both say goodbye, and you walk away, feeling both happy and regretful\n");
                printf("The end!\n");
                return 0;
            }
        } else {
            printf("\nYou continue walking, still hearing the gentle laughter of the person behind you\n");
            printf("You feel like you could have spent the whole day with them, but alas, you must continue your adventure\n");
            printf("The end!\n");
            return 0;
        }
    } else {
        printf("\nYou decide to keep walking, enjoying the sights and sounds of the countryside\n");
        printf("As you walk, you come across a beautiful meadow filled with colorful flowers and chirping birds\n");
        printf("You feel a warm sense of peace and happiness wash over you as you take it all in\n");
        printf("But as you keep walking, the feeling leaves just as quickly as it came\n");
        printf("You continue your adventure, feeling hopeful about what's to come\n");
        printf("The end!\n");
        return 0;
    }
}