//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define PASSWORD_LENGTH 32
#define TITLE_LENGTH 64

typedef struct {
    char title[TITLE_LENGTH];
    char password[PASSWORD_LENGTH];
} Entry;

Entry vault[MAX_ENTRIES];
int entry_count = 0;

void tendrils_of_fate() {
    printf("\n        🌌 Welcome to the Surreal Password Vault 🌌\n");
    printf("     Where dreams come to store their ephemeral whispers\n\n");
}

void dance_with_numbers() {
    printf("  ✨ A seed shall blossom with a number of your choosing! ✨\n");
    printf("    Please provide the spiral of destiny (max %d): ", MAX_ENTRIES);
    scanf("%d", &entry_count);

    if (entry_count > MAX_ENTRIES) {
        entry_count = MAX_ENTRIES;
        printf("    The universe limited your aspirations. Embrace %d.\n", MAX_ENTRIES);
    }
}

void pluck_the_passwords() {
    if (entry_count <= 0) {
        printf("      The garden of entries is barren. 🌱\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        Entry *current_entry = &vault[i];
        printf("      Entry #%d: ", i + 1);
        printf("Title: %s | Password: %s\n", current_entry->title, current_entry->password);
    }
}

void sow_the_seeds() {
    if (entry_count <= 0 || entry_count >= MAX_ENTRIES) {
        printf("      The soil must be nourished before planting. 🌱\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        printf("    Breathe life into entry #%d...\n", i + 1);
        printf("    Title: ");
        scanf("%s", vault[i].title);
        printf("    Whisper the password: ");
        scanf("%s", vault[i].password);
    }

    printf("    The vault has been sealed with %d entries. 🔒\n", entry_count);
}

void shatter_the_vault() {
    printf(" 🌌 🌌 🌌 The vault is dissolving... 🌌 🌌 🌌\n");
    printf("   Which entry shall float into oblivion? (1 to %d): ", entry_count);
    int idx;
    scanf("%d", &idx);

    if (idx < 1 || idx > entry_count) {
        printf("    A misguided choice! The illusion cannot be broken. 🌪️\n");
        return;
    }

    for (int i = idx - 1; i < entry_count - 1; i++) {
        vault[i] = vault[i + 1];
    }
    entry_count--;
    printf("    The entry has evaporated from existence. ☁️\n");
}

void ephemeral_navigation() {
    int choice = -1;

    while (choice != 0) {
        tendrils_of_fate();
        printf("       1. Plant new seeds of passwords\n");
        printf("       2. View existing dreams\n");
        printf("       3. Shatter the vault and o'er the abyss\n");
        printf("       0. Exit the realm of whispers\n\n");
        printf("    Choose your path: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sow_the_seeds();
                break;
            case 2:
                pluck_the_passwords();
                break;
            case 3:
                shatter_the_vault();
                break;
            case 0:
                printf("      🌌 Farewell, dream weaver! 🌌\n");
                break;
            default:
                printf("      A choice lost in the fog... Try again! 🌫️\n");
                break;
        }
    }
}

int main() {
    ephemeral_navigation();
    return 0;
}