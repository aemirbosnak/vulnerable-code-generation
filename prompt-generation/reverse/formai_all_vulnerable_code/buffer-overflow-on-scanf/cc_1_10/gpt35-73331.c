//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printIntroductoryMessage() {
	printf("Welcome to the Linux Adventure Game!\n");
	printf("You find yourself in unfamiliar territory.\n");
	printf("Your challenge is to navigate through the Linux terminal and survive.\n");
	printf("Be careful, as danger lurks around every corner!\n\n");
}

void printEnterCommandPrompt() {
	printf("Enter a command (type 'help' for a list of commands): ");
}

void help() {
	printf("Available commands:\n");
	printf("help               Prints this message.\n");
	printf("ls                 Lists the current directory.\n");
	printf("cd <directory>     Changes the current directory to <directory>.\n");
	printf("cat <file>         Output the contents of <file> to the console.\n");
	printf("grep <pattern>     Searches for the string <pattern> in the current directory and its subdirectories.\n");
	printf("mkdir <directory>  Creates a new directory named <directory>.\n");
	printf("exit               Exits the game.\n");
}

int main() {
	char command[20];
	char arg[20];

	printIntroductoryMessage();
	while(1) {
		printEnterCommandPrompt();
		scanf("%s", command);

		if(strcmp(command, "help") == 0) {
			help();
		} else if(strcmp(command, "ls") == 0) {
			system("ls");
		} else if(strcmp(command, "exit") == 0) {
			printf("Thank you for playing. Goodbye!\n");
			exit(0);
		} else if(strcmp(command, "cd") == 0) {
			scanf("%s", arg);
			if(chdir(arg) == -1) {
				printf("cd: %s: No such file or directory\n", arg);
			}
		} else if(strcmp(command, "cat") == 0) {
			scanf("%s", arg);
			char cmd[50] = "cat ";
			strcat(cmd, arg);
			system(cmd);
		} else if(strcmp(command, "grep") == 0) {
			scanf("%s", arg);
			char cmd[50] = "grep -r ";
			strcat(cmd, arg);
			system(cmd);
		} else if(strcmp(command, "mkdir") == 0) {
			scanf("%s", arg);
			char cmd[50] = "mkdir ";
			strcat(cmd, arg);
			system(cmd);
		} else {
			printf("Command not found. Type 'help' for a list of available commands.\n");
		}
	}
	return 0;
}