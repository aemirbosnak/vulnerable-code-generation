//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    FIRST_CARD = 0,
    SECOND_CARD,
    THIRD_CARD,
    NUM_CARDS
};

struct card {
    char *name;
    char *meaning;
};

struct card deck[] = {
    {"The Fool", "New beginnings, innocence, spontaneity, a free spirit"},
    {"The Magician", "Skill, creativity, resourcefulness, power"},
    {"The High Priestess", "Intuition, sacred knowledge, divine feminine"},
    {"The Empress", "Abundance, fertility, nurturing, growth"},
    {"The Emperor", "Leadership, authority, structure, worldly power"},
    {"The Hierophant", "Tradition, spirituality, conformity, religion"},
    {"The Lovers", "Partnership, choices, relationships, love"},
    {"The Chariot", "Success, determination, victory, overcoming obstacles"},
    {"Strength", "Courage, power, self-control, compassion"},
    {"The Hermit", "Solitude, introspection, wisdom, guidance"},
    {"The Wheel of Fortune", "Change, cycles, destiny, luck"},
    {"Justice", "Fairness, balance, law, cause and effect"},
    {"The Hanged Man", "Surrender, sacrifice, letting go, new perspectives"},
    {"Death", "Transformation, endings, rebirth, the unknown"},
    {"Temperance", "Harmony, balance, moderation, alchemy"},
    {"The Devil", "Temptation, materialism, bondage, shadow self"},
    {"The Tower", "Chaos, upheaval, crisis, awakening"},
    {"The Star", "Hope, inspiration, guidance, renewal"},
    {"The Moon", "Illusion, dreams, intuition, subconscious"},
    {"The Sun", "Success, vitality, joy, enlightenment"},
    {"Judgment", "Rebirth, awakening, absolution, inner calling"},
    {"The World", "Completion, integration, accomplishment, travel"}
};

void shuffle_deck(struct card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_card(struct card deck[], int position) {
    printf("Dealing card %d...\n", position + 1);
    sleep(1);
    printf("%s: %s\n", deck[position].name, deck[position].meaning);
}

int main() {
    shuffle_deck(deck);

    printf("Welcome to the Retro Automated Fortune Teller!\n");
    sleep(2);

    printf("Please choose a card:\n");
    int choice;
    scanf("%d", &choice);

    if (choice >= FIRST_CARD && choice <= THIRD_CARD) {
        deal_card(deck, choice - FIRST_CARD);
    } else {
        printf("Invalid choice. Please choose a number between 1 and 3.\n");
    }

    return 0;
}