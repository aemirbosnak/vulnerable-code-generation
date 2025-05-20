//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: puzzling
void main() {
    // Declare variables
    int i, j;
    int count = 0;
    char diary[100];

    // Get input from user
    printf("Enter your diary: ");
    scanf("%s", diary);

    // Count the number of words in the diary
    for (i = 0; diary[i] != '\0'; i++) {
        if (diary[i] == ' ') {
            count++;
        }
    }

    // Print the number of words in the diary
    printf("Your diary contains %d words.\n", count);

    // Count the number of vowels in the diary
    for (i = 0; diary[i] != '\0'; i++) {
        if (diary[i] == 'a' || diary[i] == 'e' || diary[i] == 'i' || diary[i] == 'o' || diary[i] == 'u') {
            count++;
        }
    }

    // Print the number of vowels in the diary
    printf("Your diary contains %d vowels.\n", count);

    // Count the number of consonants in the diary
    for (i = 0; diary[i] != '\0'; i++) {
        if (diary[i] != 'a' && diary[i] != 'e' && diary[i] != 'i' && diary[i] != 'o' && diary[i] != 'u') {
            count++;
        }
    }

    // Print the number of consonants in the diary
    printf("Your diary contains %d consonants.\n", count);

    // Count the number of digits in the diary
    for (i = 0; diary[i] != '\0'; i++) {
        if (diary[i] >= '0' && diary[i] <= '9') {
            count++;
        }
    }

    // Print the number of digits in the diary
    printf("Your diary contains %d digits.\n", count);

    // Count the number of special characters in the diary
    for (i = 0; diary[i] != '\0'; i++) {
        if (diary[i] != 'a' && diary[i] != 'e' && diary[i] != 'i' && diary[i] != 'o' && diary[i] != 'u' && diary[i] != 'A' && diary[i] != 'E' && diary[i] != 'I' && diary[i] != 'O' && diary[i] != 'U') {
            count++;
        }
    }

    // Print the number of special characters in the diary
    printf("Your diary contains %d special characters.\n", count);
}