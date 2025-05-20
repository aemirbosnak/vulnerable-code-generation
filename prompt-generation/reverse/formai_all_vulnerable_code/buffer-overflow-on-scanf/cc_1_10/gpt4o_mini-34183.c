//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUMBERS "0123456789"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+[]{}|;:,.<>?/~"

void knights_greet() {
    printf("Hark! Be ye ready to forge a password of unwavering strength!\n");
    printf("Let us summon the generators of entropy from the abyss!\n\n");
}

void draw_blazon(int length) {
    printf("Gather ye the arcane elements:\n");
    printf("1. Noble letters [A-Z]\n");
    printf("2. Valorous letters [a-z]\n");
    printf("3. Mystical digits [0-9]\n");
    printf("4. Special characters\n");
    printf("Now, that thou art familiar, prepare thyself for the password creation.\n\n");
}

char* generate_password(int length) {
    char *password = malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Alas! Memory allocation failed! Seek twas not achievable.\n");
        exit(1);
    }

    const char *all_characters = LOWERCASE UPPERCASE NUMBERS SPECIAL_CHARACTERS;
    int all_length = strlen(all_characters);
    
    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = all_characters[rand() % all_length];
    }
    
    password[length] = '\0'; // Null terminate the string
    return password;
}

void display_password(char *password, int length) {
    printf("Thou shalt receive thy created password of %d runes:\n", length);
    printf("%s\n\n", password);
}

void quest_for_strength() {
    int length;

    do {
        printf("Prithee, choose a length between %d and %d runes:\n", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Nay! The chosen length must be within the sacred bounds.\n");
        }
    } while (length < MIN_LENGTH || length > MAX_LENGTH);

    char *password = generate_password(length);
    display_password(password, length);
    free(password);
}

void knight_chooses() {
    int choice;
    do {
        printf("What dost thou wish to do?\n");
        printf("1. Generate a Secure Password\n");
        printf("2. Depart from this realm\n");
        printf("Choose thy path (1 or 2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quest_for_strength();
                break;
            case 2:
                printf("Farewell, brave knight! May fortune favor thee in thy endeavors!\n");
                break;
            default:
                printf("Thou hast entered an invalid choice! Choose again.\n\n");
                break;
        }
    } while (choice != 2);
}

int main() {
    knights_greet();
    draw_blazon(MIN_LENGTH);
    knight_chooses();
    return 0;
}