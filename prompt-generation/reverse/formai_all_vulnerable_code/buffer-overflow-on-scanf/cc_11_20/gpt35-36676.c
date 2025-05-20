//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char name[50];
    int choice;
    
    printf("Welcome to the post-apocalyptic world!\n");
    printf("What's your name survivor?\n");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
    printf("\n");

    printf("%s, you find yourself in the middle of a ruined city.\n", name);
    printf("You are alone with nothing but the clothes on your back and a small backpack with some supplies.\n");
    printf("You see a few buildings and streets leading in different directions.\n");
    printf("What do you want to do?\n\n");

    printf("1. Search for shelter\n");
    printf("2. Look for food and water\n");
    printf("3. Explore the city\n\n");

    printf("Enter your choice: ");

    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice, please select a number between 1 and 3: ");
        clearInputBuffer();
    }

    clearInputBuffer();

    if(choice == 1) {
        printf("\nYou find an abandoned building and decide to take a look.\n");
        printf("You search the place and find a room that seems relatively safe.\n");
        printf("However, there are strange noises coming from below.\n\n");
        printf("What do you want to do?\n\n");

        printf("1. Investigate the noises\n");
        printf("2. Ignore the noises and rest\n\n");

        printf("Enter your choice: ");

        while(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
            printf("Invalid choice, please select a number between 1 and 2: ");
            clearInputBuffer();
        }

        clearInputBuffer();

        if(choice == 1) {
            printf("\nYou cautiously make your way down the stairs into the basement.\n");
            printf("You find a group of survivors huddled together, trying to keep warm.\n");
            printf("They tell you about a nearby compound where they have been staying.\n");
            printf("They offer to take you with them.\n\n");

            printf("What do you want to do?\n\n");

            printf("1. Go with the survivors\n");
            printf("2. Decline and continue on your own\n\n");

            printf("Enter your choice: ");

            while(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
                printf("Invalid choice, please select a number between 1 and 2: ");
                clearInputBuffer();
            }

            clearInputBuffer();

            if(choice == 1) {
                printf("\nYou decide to go with the survivors to the compound.\n");
                printf("After a few hours of walking, you finally reach the compound.\n");
                printf("It's a heavily fortified place with plenty of resources and people.\n");
                printf("You feel relieved and safe for the first time in a long while.\n");
                printf("Congratulations, you have survived!\n");
            }
            else {
                printf("\nYou decline the offer and continue on your own.\n");
                printf("As you leave the building, you hear gunshots in the distance.\n");
                printf("You decide to change direction and head towards the sound.\n");
                printf("Maybe you can find some more survivors or supplies.\n");
                printf("Good luck!\n");
            }
        }
        else {
            printf("\nYou decide to rest and ignore the noises.\n");
            printf("As you drift off to sleep, you hear something sneaking up on you.\n");
            printf("You try to defend yourself, but it's too late.\n");
            printf("Game over, you have died.\n");
        }
    }
    else if(choice == 2) {
        printf("\nYou wander around the city to find some food and water.\n");
        printf("After a few hours of searching, you stumble upon an abandoned supermarket.\n");
        printf("It's been looted, but you manage to find some canned goods and bottled water.\n");
        printf("You take what you can and head out of the store.\n");
        printf("As you leave, you notice a group of raiders approaching.\n\n");

        printf("What do you want to do?\n\n");

        printf("1. Hide and wait for them to pass\n");
        printf("2. Fight them off\n\n");

        printf("Enter your choice: ");

        while(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
            printf("Invalid choice, please select a number between 1 and 2: ");
            clearInputBuffer();
        }

        clearInputBuffer();

        if(choice == 1) {
            printf("\nYou quickly hide behind some nearby cars and wait for the raiders to pass.\n");
            printf("After a few tense minutes, the coast is clear and you can continue on your way.\n");
            printf("You find a safe place to rest and consume your newly acquired supplies.\n");
            printf("Congratulations, you have survived!\n");
        }
        else {
            printf("\nYou decide to fight the raiders off to protect your supplies.\n");
            printf("You manage to take a few of them out, but they overpower you.\n");
            printf("Game over, you have died.\n");
        }
    }
    else {
        printf("\nYou start exploring the city, hoping to find anything useful.\n");
        printf("As you walk, you hear footsteps behind you.\n");
        printf("You turn around and see a group of mutants charging at you.\n\n");

        printf("What do you want to do?\n\n");

        printf("1. Run for your life\n");
        printf("2. Stand your ground and fight\n\n");

        printf("Enter your choice: ");

        while(scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
            printf("Invalid choice, please select a number between 1 and 2: ");
            clearInputBuffer();
        }

        clearInputBuffer();

        if(choice == 1) {
            printf("\nYou run as fast as you can, hoping to outrun the mutants.\n");
            printf("You manage to escape, but you're exhausted and lost.\n");
            printf("You eventually succumb to your injuries, hunger, and thirst.\n");
            printf("Game over, you have died.\n");
        }
        else {
            printf("\nYou decide to stand your ground and fight.\n");
            printf("It's a tough battle, but you manage to fend off the mutants.\n");
            printf("You find a nearby building to rest and regroup.\n");
            printf("Congratulations, you have survived!\n");
        }
    }

    return 0;
}