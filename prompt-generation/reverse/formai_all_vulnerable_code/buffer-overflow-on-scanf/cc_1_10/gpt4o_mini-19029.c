//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFortune(char* fortune) {
    printf("\n🌟🔮 Your Fortune: %s 🔮🌟\n", fortune);
}

void displayMenu() {
    printf("\nWelcome to the Great and Powerful C Fortune Teller!\n");
    printf("What would you like to do?\n");
    printf("1. Ask a silly question\n");
    printf("2. Check your fortune with a funny twist\n");
    printf("3. Tell me your favorite vegetable\n");
    printf("4. Exit the mystic realm\n");
}

char* getFortune() {
    char* fortunes[] = {
        "You will trip over a banana peel today.",
        "A squirrel will reveal the secrets of the universe to you.",
        "You will become the world's leading expert on bubble wrap.",
        "Your future spouse shall be a talking plant.",
        "You will discover that cats are actually plotting against you.",
        "A pizza slice will be your greatest teacher.",
        "Your next meal will be too spicy for your taste buds to handle.",
        "Today is a great day to wear mismatched socks.",
        "A spoonful of jam will change your life forever.",
        "You will find a sock without a partner and it will lead you to enlightenment."
    };
    return fortunes[rand() % 10];
}

void askSillyQuestion() {
    char question[256];
    printf("\nAsk me a silly question (e.g., 'Will I ever win a wet sock contest?'):\n");
    fgets(question, sizeof(question), stdin);
    printf("Hmm... Let me consult the cosmic forces...\n");
    sleep(2);
    char* fortune = getFortune();
    printFortune(fortune);
}

void favoriteVegetable() {
    char vegetable[50];
    printf("What is your favorite vegetable?\n");
    fgets(vegetable, sizeof(vegetable), stdin);
    printf("Interesting choice! The Cosmic Spirits say:\n");
    sleep(1);
    if (strstr(vegetable, "carrot")) {
        printf("Carrots are great, but don't forget about the importance of broccoli!\n");
    } else if (strstr(vegetable, "broccoli")) {
        printf("Broccoli, a wise choice! Just don’t let it know you prefer pizza!\n");
    } else {
        printf("%s is cool! Just remember, the radishes envy your taste.\n", vegetable);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from stdin

        switch (choice) {
            case 1:
                askSillyQuestion();
                break;
            case 2:
                printf("Let me see what the universe has in store for you...\n");
                sleep(2);
                char* fortune = getFortune();
                printFortune(fortune);
                break;
            case 3:
                favoriteVegetable();
                break;
            case 4:
                printf("Thank you for visiting the C Automated Fortune Teller! May your future be filled with snacks!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice! Maybe try asking your cat?\n");
        }
    }
    return 0;
}