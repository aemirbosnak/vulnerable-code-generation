//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>
#include <string.h>

void expressLove(int level, char *recipient, int maxLevel) {
    // Base case: if we've reached the maximum level, stop the recursion
    if (level > maxLevel) {
        return;
    }

    // Prepare the love letter based on the current level
    char letter[256];

    // Crafting the letter with increasing depth of affection
    switch(level) {
        case 1:
            sprintf(letter, "Dear %s,\nEvery day I find myself cherishing you more.\n", recipient);
            break;
        case 2:
            sprintf(letter, "Dear %s,\nAs the stars light up the night sky, so do you illuminate my world.\n", recipient);
            break;
        case 3:
            sprintf(letter, "Dear %s,\nIn gardens of love, you are the rarest flower, blooming eternally in my heart.\n", recipient);
            break;
        case 4:
            sprintf(letter, "Dear %s,\nEach moment spent with you is a precious treasure; your laughter resonates like a love melody.\n", recipient);
            break;
        case 5:
            sprintf(letter, "Dear %s,\nYou, my love, are the poetry that dances in my soul, an eternal spring of joy.\n", recipient);
            break;
        default:
            sprintf(letter, "Dear %s,\nMy love for you knows no bounds, it is an endless story.\n", recipient);
            break;
    }

    // Print the love letter
    printf("%s\n", letter);

    // Recursively call expressLove to create deeper connections
    expressLove(level + 1, recipient, maxLevel);
}

int main() {
    char recipient[50];
    int maxLevel;

    // Introduction to the love letter experience
    printf("Welcome to the Expressive Love Letter Generator!\n");
    printf("Please enter the name of your beloved: ");
    fgets(recipient, sizeof(recipient), stdin);

    // Remove newline character from recipient
    recipient[strcspn(recipient, "\n")] = 0;

    printf("How many layers of love do you wish to express? (1-5): ");
    scanf("%d", &maxLevel);

    // Check for valid level input
    if (maxLevel < 1 || maxLevel > 5) {
        printf("Please choose a level between 1 and 5.\n");
        return 1;
    }

    // Start expressing love through recursion
    expressLove(1, recipient, maxLevel);

    printf("Thank you for sharing your love!\n");
    return 0;
}