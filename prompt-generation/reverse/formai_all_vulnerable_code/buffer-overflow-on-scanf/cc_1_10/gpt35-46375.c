//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LEN 20
#define MAX_FILE_CONTENT_LEN 100

typedef struct{
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_CONTENT_LEN];
    int version;
}File;

typedef struct{
    int id;
    File files[MAX_FILES];
    int file_count;
}Player;

void print_menu(){
    printf("\nWelcome to the File Backup System!\n\n");
    printf("1. Create a new player\n");
    printf("2. Add a file to a player's library\n");
    printf("3. Backup a player's file\n");
    printf("4. Print a player's file library\n");
    printf("5. Print a player's backed up files\n");
    printf("6. Exit\n\n");
}

void create_player(Player *players, int *player_count){
    if(*player_count == MAX_FILES){
        printf("\nCannot create more players, limit reached\n");
        return;
    }

    Player new_player;
    new_player.file_count = 0;
    new_player.id = *player_count + 1;

    players[*player_count] = new_player;
    (*player_count)++;

    printf("\nNew player created with ID %d\n", new_player.id);
}

void add_file(Player *player){
    if(player->file_count == MAX_FILES){
        printf("\nCannot add more files to library, limit reached\n");
        return;
    }

    File new_file;
    printf("Enter file name (max %d characters): ", MAX_FILE_NAME_LEN);
    scanf("%s", new_file.name);
    printf("Enter file content (max %d characters): ", MAX_FILE_CONTENT_LEN);
    scanf("%s", new_file.content);
    new_file.version = 1;

    player->files[player->file_count] = new_file;
    player->file_count++;

    printf("\nFile added to player's library\n");
}

void backup_file(Player *player, Player *backup_players, int player_count){
    if(player->file_count == 0){
        printf("\nNo files in player's library to backup\n");
        return;
    }

    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    for(int i=0; i<player->file_count; i++){
        if(strcmp(player->files[i].name, file_name) == 0){
            File backup_file = player->files[i];

            for(int j=0; j<player_count; j++){
                if(backup_players[j].id == player->id) continue;

                backup_players[j].files[backup_players[j].file_count] = backup_file;
                backup_players[j].file_count++;
            }

            backup_file.version++;

            player->files[i] = backup_file;
            printf("\nFile backed up successfully\n");
            return;
        }
    }

    printf("\nFile with given name not found\n");
}

void print_library(Player player){
    printf("\nPrinting library for player with ID %d\n", player.id);
    printf("File Name\tContent\t\tVersion\n");
    for(int i=0; i<player.file_count; i++){
        printf("%s\t\t%s\t\t%d\n", player.files[i].name, player.files[i].content, player.files[i].version);
    }
}

void print_backups(Player player, Player *backup_players, int player_count){
    printf("\nPrinting backups for player with ID %d\n", player.id);
    printf("File Name\tBackup player ID\t\tContent\t\tVersion\n");

    for(int i=0; i<player.file_count; i++){
        printf("%s\t\t", player.files[i].name);

        for(int j=0; j<player_count; j++){
            if(backup_players[j].id == player.id) continue;

            for(int k=0; k<backup_players[j].file_count; k++){
                if(strcmp(player.files[i].name, backup_players[j].files[k].name) == 0){
                    printf("%d ", backup_players[j].id);
                    printf("\t\t%s\t\t%d\n", backup_players[j].files[k].content, backup_players[j].files[k].version);
                    break;
                }
            }
        }
    }
}

int main(){
    Player players[MAX_FILES];
    Player backup_players[MAX_FILES];
    int player_count = 0;

    int choice = -1;
    while(choice != 6){
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                create_player(players, &player_count);
                break;
            case 2: 
                printf("\nEnter ID of player to add file to: ");
                int player_id;
                scanf("%d", &player_id);

                for(int i=0; i<player_count; i++){
                    if(players[i].id == player_id){
                        add_file(&players[i]);
                        break;
                    }
                }
                break;
            case 3: 
                printf("\nEnter ID of player to backup file from: ");
                int backup_id;
                scanf("%d", &backup_id);

                for(int i=0; i<player_count; i++){
                    if(players[i].id == backup_id){
                        backup_file(&players[i], backup_players, player_count);
                        break;
                    }
                }
                break;
            case 4: 
                printf("\nEnter ID of player to print library of: ");
                int library_id;
                scanf("%d", &library_id);

                for(int i=0; i<player_count; i++){
                    if(players[i].id == library_id){
                        print_library(players[i]);
                        break;
                    }
                }
                break;
            case 5: 
                printf("\nEnter ID of player to print backups of: ");
                int backups_id;
                scanf("%d", &backups_id);

                for(int i=0; i<player_count; i++){
                    if(players[i].id == backups_id){
                        print_backups(players[i], backup_players, player_count);
                        break;
                    }
                }
                break;
            case 6: 
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option, try again\n");
        }
    }

    return 0;
}