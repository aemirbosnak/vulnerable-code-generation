//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Hey there, let's build a FTP Client, but with a twist!\n");
    printf("We are going to use only emojis to communicate with the server!\n");
    printf("Here we go!\n\n");

    //Establishing connection with server
    printf("🌐 Connecting to the server 🌐\n");

    //Authentication process
    printf("🔒 Authenticating with the server 🔒\n");
    printf("👤 Enter your username: ");
    char username[50];
    scanf("%s", username);
    printf("🔑 Enter your password: ");
    char password[50];
    scanf("%s", password);
    printf("🔓 Authentication successful! 🔓\n");

    //Navigating to specific directory in server
    printf("📂 Navigating to specific directory in server 📂\n");
    printf("📁 Enter directory name: ");
    char directory[50];
    scanf("%s", directory);
    printf("🚶 Navigating to directory '%s' 🚶\n");

    //Downloading file from server
    printf("📥 Downloading file from server 📥\n");
    printf("📄 Enter filename: ");
    char filename[50];
    scanf("%s", filename);
    printf("⬇️ Downloading file '%s' from server ⬇️\n", filename);

    //Uploading file to server
    printf("📤 Uploading file to server 📤\n");
    printf("📄 Enter filename: ");
    scanf("%s", filename);
    printf("⬆️ Uploading file '%s' to server ⬆️\n", filename);

    //Closing connection with server
    printf("👋 Closing connection with server 👋\n");
    printf("🔌 Connection closed 🔌\n");

    printf("\n\nThat was fun! Let's do it again sometime!\n");

    return 0;
}