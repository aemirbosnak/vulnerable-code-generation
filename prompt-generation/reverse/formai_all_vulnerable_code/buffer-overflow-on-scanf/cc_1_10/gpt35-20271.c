//FormAI DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the Artistic System Administration Program!\n\n");

    sleep(1);

    printf("In this program, we will help you manage your system resources in a unique and artistic way!\n\n");

    sleep(1);

    printf("We will start by showing you the current status of your system:\n\n");

    system("top");

    printf("\n\nNow, let's add a personal touch to your system by changing the command prompt to something more creative!\n\n");

    sleep(1);

    char prompt[20];

    printf("Enter a new prompt: ");

    scanf("%s", prompt);

    setenv("PS1", prompt, 1);

    printf("\n\nGreat! Your new prompt is set to: %s\n\n", prompt);

    sleep(1);

    printf("Now, let's give your system a unique wallpaper to match your artistic style!\n\n");

    sleep(1);

    char wallpaper[50];

    printf("Enter the path to the image file: ");

    scanf("%s", wallpaper);

    char command[50];

    sprintf(command, "feh --bg-scale %s", wallpaper);

    system(command);

    printf("\n\nAwesome! Your new wallpaper is set!\n\n");

    sleep(1);

    printf("Finally, let's add a touch of color to your system by changing the terminal font color:\n\n");

    sleep(1);

    char color[20];

    printf("Enter a color name or code (e.g. green, #FF0000): ");

    scanf("%s", color);

    char color_command[50];

    sprintf(color_command, "echo -e \"\\033[0;32m\\033[1;%s\" > ~/.bashrc", color);

    system(color_command);

    printf("\n\nFantastic! Your new font color is set to: %s\n\n", color);

    sleep(1);

    printf("Thank you for using the Artistic System Administration Program. Your system is now a true masterpiece!\n\n");

    return 0;
}