//FormAI DATASET v1.0 Category: Image Editor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_COMMAND_LENGTH 50
#define MAX_FILENAME_LENGTH 20

// global variables
char filenames[MAX_PLAYERS][MAX_FILENAME_LENGTH] = {"image1.bmp", "image2.bmp", "image3.bmp", "image4.bmp"};
int player_fds[MAX_PLAYERS][2]; // communication between players
int server_fds[MAX_PLAYERS][2]; // communication between server and players
int active_players = 0;

int main(int argc, char *argv[]) {
    // initialize pipes for players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (pipe(player_fds[i]) == -1 || pipe(server_fds[i]) == -1) {
            perror("pipe failed");
            exit(1);
        }
    }

    // initialize child processes
    pid_t pids[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pids[i] = fork();
        if (pids[i] < 0) {
            perror("fork failed");
            exit(1);
        } else if (pids[i] == 0) { // child process
            close(player_fds[i][1]); // close writing end for player
            close(server_fds[i][0]); // close reading end for server
            while (1) { // player loop
                char command[MAX_COMMAND_LENGTH];
                int bytes_read = read(player_fds[i][0], &command, MAX_COMMAND_LENGTH);
                if (bytes_read > 0) {
                    // process command
                    if (strcmp(command, "load") == 0) {
                        // load image file
                        char filename[MAX_FILENAME_LENGTH];
                        read(player_fds[i][0], &filename, MAX_FILENAME_LENGTH);
                        sprintf(filenames[i], "%s_player%d.bmp", filename, i+1);
                        // send confirmation to server
                        char confirmation[] = "loaded";
                        write(server_fds[i][1], &confirmation, strlen(confirmation)+1);
                    } else if (strcmp(command, "save") == 0) {
                        // save image file
                        char filename[MAX_FILENAME_LENGTH];
                        read(player_fds[i][0], &filename, MAX_FILENAME_LENGTH);
                        sprintf(filenames[i], "%s_player%d.bmp", filename, i+1);
                        // send confirmation to server
                        char confirmation[] = "saved";
                        write(server_fds[i][1], &confirmation, strlen(confirmation)+1);
                    } else if (strcmp(command, "exit") == 0) {
                        // exit player process
                        exit(0);
                    }
                } else if (bytes_read == -1) { // error
                    perror("read failed");
                    exit(1);
                }
            }
        } else { // parent process
            active_players++;
            close(player_fds[i][0]); // close reading end for player
            close(server_fds[i][1]); // close writing end for server
        }
    }

    // server loop
    char command[MAX_COMMAND_LENGTH];
    while (active_players > 0) {
        printf("Enter command (load/save): ");
        scanf("%s", command);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (pids[i] != 0) {
                // send command to player
                write(player_fds[i][1], &command, strlen(command)+1);
                if (strcmp(command, "load") == 0 || strcmp(command, "save") == 0) {
                    // get filename from user
                    char filename[MAX_FILENAME_LENGTH];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    write(player_fds[i][1], &filename, strlen(filename)+1);
                    // wait for confirmation from player
                    char confirmation[MAX_COMMAND_LENGTH];
                    int bytes_read = read(server_fds[i][0], &confirmation, MAX_COMMAND_LENGTH);
                    if (bytes_read > 0) {
                        printf("%s %s_player%d.bmp\n", confirmation, filename, i+1);
                    } else if (bytes_read == -1) { // error
                        perror("read failed");
                        exit(1);
                    }
                }
            }
        }
    }

    return 0;
}