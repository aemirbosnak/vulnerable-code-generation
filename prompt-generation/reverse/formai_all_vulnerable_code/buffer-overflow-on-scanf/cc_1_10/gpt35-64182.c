//FormAI DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <string.h>

void changePassword(char *password);
char *getPassword();

int main() {
	char *password = getPassword();

	// Check if password is empty or too short
	if (strlen(password) == 0 || strlen(password) < 6) {
		printf("Invalid Password! Password must be at least 6 characters long.\n");
	} else {
		// Password is valid, we can proceed
		printf("Welcome! You are now logged in.\n");

		// Prompt user to change password
		char choice;
		printf("Would you like to change your password? (Y/N)\n");
		scanf(" %c", &choice);
		
		if (choice == 'Y' || choice == 'y') {
			changePassword(password);
		}

		// Log user out
		printf("You have been logged out. Goodbye!\n");
	}

	return 0;
}

// This function prompts the user for their password and returns it as a string
char *getPassword() {
	static char password[128]; // Static allows retaining value after function call

	printf("Please enter your password: ");
	scanf("%s", password);

	return password;
}

// This function allows the user to change their password
void changePassword(char *password) {
	char newPassword[128];

	// Prompt user for new password and confirm it
	printf("\nPlease enter your new password: ");
	scanf("%s", newPassword);

	char confirmation[128];
	printf("Please confirm your new password: ");
	scanf("%s", confirmation);

	if (strcmp(newPassword, confirmation) != 0) {
		printf("\nPasswords do not match. Please try again.\n\n");
		changePassword(password);
	} else if (strlen(newPassword) < 6) {
		printf("\nInvalid Password! Password must be at least 6 characters long.\n\n");
		changePassword(password);
	} else if (strcmp(password, newPassword) == 0) {
		printf("\nNew password cannot be the same as old password. Please try again.\n\n");
		changePassword(password);
	} else {
		strcpy(password, newPassword);
		printf("\nPassword changed successfully.\n\n");
	}
}