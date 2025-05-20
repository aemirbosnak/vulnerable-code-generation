//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include<stdio.h>
#include<string.h>

/*Here we have defined the Cat Language*/
#define meow printf("Meow! ");
#define purr printf("Purr! ");
#define hiss printf("Hiss! ");

/*The following function takes in a phrase in Cat Language and translates it to English*/
void translateCatToEnglish(char phrase[]) {
    int n = strlen(phrase);
    int i = 0;
    while (i < n) {
        if (phrase[i] == 'm' && phrase[i+1] == 'e' && phrase[i+2] == 'o' && phrase[i+3] == 'w') {
            printf("Cat says: Meow\n");
            i += 4;
        }
        else if (phrase[i] == 'p' && phrase[i+1] == 'u' && phrase[i+2] == 'r' && phrase[i+3] == 'r') {
            printf("Cat says: Purr\n");
            i += 4;
        }
        else if (phrase[i] == 'h' && phrase[i+1] == 'i' && phrase[i+2] == 's' && phrase[i+3] == 's') {
            printf("Cat says: Hiss\n");
            i += 4;
        }
        else {
            printf("Invalid input!\n");
            break;
        }
    }
}

/*The following function takes in a phrase in English and translates it to Cat Language*/
void translateEnglishToCat(char phrase[]) {
    int n = strlen(phrase);
    int i = 0;
    while (i < n) {
        if (phrase[i] == 'M' && phrase[i+1] == 'e' && phrase[i+2] == 'o' && phrase[i+3] == 'w') {
            meow;
            i += 4;
        }
        else if (phrase[i] == 'P' && phrase[i+1] == 'u' && phrase[i+2] == 'r' && phrase[i+3] == 'r') {
            purr;
            i += 4;
        }
        else if (phrase[i] == 'H' && phrase[i+1] == 'i' && phrase[i+2] == 's' && phrase[i+3] == 's') {
            hiss;
            i += 4;
        }
        else {
            printf("Invalid input!\n");
            break;
        }
    }
}

/*The main function*/
int main() {
    int choice, i = 0;
    char phrase[100];

    /*Menu*/
    while (i != 1) {
        printf("Please choose an option:\n");
        printf("1. Translate Cat Language to English\n");
        printf("2. Translate English to Cat Language\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter the phrase in Cat Language: ");
                getchar();
                fgets(phrase, sizeof(phrase), stdin);
                translateCatToEnglish(phrase);
                break;

            case 2:
                printf("Enter the phrase in English: ");
                getchar();
                fgets(phrase, sizeof(phrase), stdin);
                translateEnglishToCat(phrase);
                break;

            case 3:
                printf("Quitting program...\n");
                i = 1;
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}