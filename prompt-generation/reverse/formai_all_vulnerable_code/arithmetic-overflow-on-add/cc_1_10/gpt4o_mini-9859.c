//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 128
#define NUM_PLAYERS 3

typedef struct {
    char upper[26];
    char lower[26];
    char numbers[10];
    char special[11];

    int upper_count;
    int lower_count;
    int numbers_count;
    int special_count;
} PasswordPool;

void initializePool(PasswordPool *pool) {
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        pool->upper[pool->upper_count++] = ch;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        pool->lower[pool->lower_count++] = ch;
    }
    for (char ch = '0'; ch <= '9'; ch++) {
        pool->numbers[pool->numbers_count++] = ch;
    }
    strcpy(pool->special, "!@#$%^&*()");
    pool->special_count = strlen(pool->special);
}

void generatePassword(PasswordPool *pool, char *password, int length) {
    if (length < 1 || length > MAX_LENGTH) {
        printf("Password length must be between 1 and %d.\n", MAX_LENGTH);
        return;
    }
    
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int category = rand() % 4;  // Choose category
        switch (category) {
            case 0:  // Uppercase
                password[i] = pool->upper[rand() % pool->upper_count];
                break;
            case 1:  // Lowercase
                password[i] = pool->lower[rand() % pool->lower_count];
                break;
            case 2:  // Numbers
                password[i] = pool->numbers[rand() % pool->numbers_count];
                break;
            case 3:  // Special
                password[i] = pool->special[rand() % pool->special_count];
                break;
        }
    }
    password[length] = '\0'; // Null-terminate the password
}

void playerContribution(PasswordPool *pool, const char* type) {
    if (strcmp(type, "upper") == 0) {
        printf("Player adds Uppercase characters (A-Z):\n");
        for (int i = 0; i < pool->upper_count; i++) {
            printf("%c ", pool->upper[i]);
        }
        printf("\n");
    } else if (strcmp(type, "lower") == 0) {
        printf("Player adds Lowercase characters (a-z):\n");
        for (int i = 0; i < pool->lower_count; i++) {
            printf("%c ", pool->lower[i]);
        }
        printf("\n");
    } else if (strcmp(type, "numbers") == 0) {
        printf("Player adds Numbers (0-9):\n");
        for (int i = 0; i < pool->numbers_count; i++) {
            printf("%c ", pool->numbers[i]);
        }
        printf("\n");
    } else if (strcmp(type, "special") == 0) {
        printf("Player adds Special characters (!@#$%^&*()):\n");
        for (int i = 0; i < pool->special_count; i++) {
            printf("%c ", pool->special[i]);
        }
        printf("\n");
    }
}

int main() {
    PasswordPool pool;
    initializePool(&pool);
    
    char password[MAX_LENGTH + 1];
    int length;
    printf("Enter the desired password length (1 - %d): ", MAX_LENGTH);
    scanf("%d", &length);
    
    for (int i = 0; i < NUM_PLAYERS; i++) {
        char type[20];
        printf("Player %d, specify type to add (upper/lower/numbers/special): ", i + 1);
        scanf("%s", type);
        playerContribution(&pool, type);
    }
    
    generatePassword(&pool, password, length);
    printf("Generated Password: %s\n", password);
    
    return 0;
}