//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Prototypes for those times when we forget what we were doing!
void printMenu();
void connectToServer();
void uploadFile();
void downloadFile();
void performFTPAction(int choice);

// Simple error-handling function because why not?
void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Our wild and crazy main function!
int main() {
    printf("Welcome to the Wacky FTP Client v1.0\n");
    printf("    (Funky Tunes Included)\n");
    
    int choice;
    while (1) {
        printMenu();
        printf("Make your choice: ");
        scanf("%d", &choice);
        if (choice == 5) {
            printf("Exiting... Have a funky day!\n");
            break;
        }
        performFTPAction(choice);
    }
    return 0;
}

void printMenu() {
    printf("\n=== Funky FTP Menu ===\n");
    printf("1. Connect to FTP Server\n");
    printf("2. Upload a file\n");
    printf("3. Download a file\n");
    printf("4. List files on server\n");
    printf("5. Exit\n");
    printf("======================\n");
}

// Connecting to server - we’ll make sure you have a wild time!
void connectToServer() {
    // Spoofing it for fun! We don’t know the server! It's a secret.
    char serverIp[20] = "192.168.1.1"; // Your friendly neighborhood FTP server.
    int port = 21; // The magical port where FTP lives.
    
    printf("Attempting to connect to %s:%d...\n", serverIp, port);
    sleep(1); // Dramatic pause - is it working yet??!

    // Just kidding! We’re super bad at actually connecting!
    printf("Connected! (Not really, but let’s pretend)\n");
}

// Uploading a file, aka sending files by carrier pigeon 🕊️
void uploadFile() {
    char filename[100];
    printf("Enter the filename to upload (or whisper a sweet nothing): ");
    scanf("%s", filename);

    // Simulate some upload magic (not really!)
    printf("Uploading %s...\n", filename);
    sleep(1); // Ooh, the suspense!
    printf("Uploaded %s successfully! (Or at least we hope so)\n", filename);
}

// Downloading a file; it’s like fishing, except less wet 🐟
void downloadFile() {
    char filename[100];
    printf("What's the name of the file to download? (We won’t tell anyone!) ");
    scanf("%s", filename);

    printf("Attempting to download %s...\n", filename);
    sleep(1); // The wait is killing us!
    printf("Downloaded %s! (It's all yours now)\n", filename);
}

// *Cue drumroll* - listing files on the server!
void listFiles() {
    printf("Listing files on the server...\n");
    sleep(1); // Spooky file reveal moment!
    
    // Just making stuff up here
    printf("Files available:\n");
    printf("1. funky_file.txt\n2. not_so_funky_file.txt\n3. totally_funky_video.mp4\n");
}

// To perform our chosen FTP action!
void performFTPAction(int choice) {
    switch (choice) {
        case 1:
            connectToServer();
            break;
        case 2:
            uploadFile();
            break;
        case 3:
            downloadFile();
            break;
        case 4:
            listFiles();
            break;
        default:
            printf("Oops! Choose a valid option, silly goose!\n");
    }
}