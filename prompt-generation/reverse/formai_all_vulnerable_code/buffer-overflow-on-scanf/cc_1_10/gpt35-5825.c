//FormAI DATASET v1.0 Category: File Encyptor ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PLAYERS 10
#define MAX_FILE_SIZE 1000

struct Player {
    char name[20];
    int score;
};

// function to generate random key
int generate_key() {
    srand(time(0));
    return rand() % 26;
}

// function to encrypt file using random key
void encrypt_file(char* filename, int key) {
    char ch;
    FILE *fp, *fq;
    fp = fopen(filename, "r");      // open original file in read mode
    fq = fopen("temp.txt", "w");    // create temporary file in write mode

    while((ch = fgetc(fp)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';     // encrypt lowercase character
        }
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';     // encrypt uppercase character
        }
        fputc(ch, fq);      // write encrypted character to temporary file
    }

    fclose(fp);
    fclose(fq);

    // rename temporary file to original file
    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    int num_players, i, key;
    struct Player players[MAX_PLAYERS];

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // get player names
    for(i=0; i<num_players; i++) {
        printf("\nEnter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // get filename
    char filename[50];
    printf("\nEnter name of file to encrypt: ");
    scanf("%s", filename);

    // read file and encrypt using random key
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    long int file_size = ftell(fp);
    fclose(fp);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds maximum limit!");
        exit(1);
    }

    key = generate_key();   // generate random key
    encrypt_file(filename, key);    // encrypt file using random key

    printf("\nFile encrypted successfully!\n");
    printf("Key used for encryption: %d\n", key);

    // play game to guess key
    int guess;
    printf("\nPlayer 1: %s, enter your guess for the key: ", players[0].name);
    scanf("%d", &guess);

    for(i=1; i<num_players; i++) {
        printf("\nPlayer %d: %s, enter your guess for the key: ", i+1, players[i].name);
        scanf("%d", &guess);

        if (guess == key) {
            printf("Congratulations! You have guessed the correct key.\n");
            players[i].score += 10;
            break;
        } else {
            printf("Incorrect guess! Try again.\n");
        }
    }

    if (i == num_players) {
        printf("No one guessed the correct key. The key was: %d\n", key);
    }

    // display scores
    printf("\nScores:\n");
    for(i=0; i<num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}