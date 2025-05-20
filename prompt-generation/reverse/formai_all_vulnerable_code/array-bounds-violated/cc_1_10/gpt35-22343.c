//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>

#define MAX_PLAYERS 10

struct Player {
    int id;
    char name[20];
    unsigned char health; // Health between 0-100, represented with 1 byte
    unsigned char armor;  // Armor between 0-100, represented with 1 byte
    unsigned int ammo;    // Ammo between 0-65536, represented with 2 bytes
    unsigned int score;   // Score between 0-4294967295, represented with 4 bytes
};

void print_player_info(struct Player player) {
    printf("\nPlayer info:\nID: %d\nName: %s\nHealth: %d\nArmor: %d\nAmmo: %d\nScore: %d\n",
           player.id, player.name, player.health, player.armor, player.ammo, player.score);
}

// Bitwise operations to encode and decode player data
unsigned char encode_health_armor(unsigned char health, unsigned char armor) {
    return (health << 2) | armor;
}

void decode_health_armor(unsigned char health_armor, unsigned char *health, unsigned char *armor) {
    *armor = health_armor & 0x03;
    *health = (health_armor >> 2) & 0x3F;
}

unsigned int encode_ammo_score(unsigned int ammo, unsigned int score) {
    return (ammo << 16) | score;
}

void decode_ammo_score(unsigned int ammo_score, unsigned int *ammo, unsigned int *score) {
    *score = ammo_score & 0xFFFF;
    *ammo = (ammo_score >> 16) & 0xFFFF;
}

int main() {
    struct Player players[MAX_PLAYERS];

    // Initialize players
    players[0].id = 1;
    strcpy(players[0].name, "Player 1");
    players[0].health = 100;
    players[0].armor = 50;
    players[0].ammo = 1000;
    players[0].score = 0;

    players[1].id = 2;
    strcpy(players[1].name, "Player 2");
    players[1].health = 75;
    players[1].armor = 25;
    players[1].ammo = 500;
    players[1].score = 500;

    // Send player data to other players
    unsigned char buffer[MAX_PLAYERS * 8];
    int buffer_index = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].id != 0) {
            buffer[buffer_index++] = players[i].id;
            buffer[buffer_index++] = strlen(players[i].name);
            strcpy(&buffer[buffer_index], players[i].name);
            buffer_index += strlen(players[i].name);
            buffer[buffer_index++] = encode_health_armor(players[i].health, players[i].armor);
            unsigned int ammo_score = encode_ammo_score(players[i].ammo, players[i].score);
            memcpy(&buffer[buffer_index], &ammo_score, sizeof(unsigned int));
            buffer_index += sizeof(unsigned int);
        }
    }

    // Receive player data from other players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (buffer[i * 8] != 0) {
            struct Player player;
            player.id = buffer[i * 8];
            int name_length = buffer[i * 8 + 1];
            strncpy(player.name, &buffer[i * 8 + 2], name_length);
            buffer_index = i * 8 + 2 + name_length;
            decode_health_armor(buffer[buffer_index++], &player.health, &player.armor);
            unsigned int ammo_score;
            memcpy(&ammo_score, &buffer[buffer_index], sizeof(unsigned int));
            decode_ammo_score(ammo_score, &player.ammo, &player.score);
            print_player_info(player);
        }
    }

    return 0;
}