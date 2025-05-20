//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Account{
	int accountNumber;
	char name[100];
	float balance;
}Account;

void createAccount(Account* account) {
	scanf("%d %s %f", &account->accountNumber, account->name, &account->balance);
}

void displayAccount(Account* account) {
	printf("%d %s %f\n", account->accountNumber, account->name, account->balance);
}

int main() {
	Account accounts[10];
	int choice, num, i;
	char ch;

	while (1) {
		printf("\n\nBanking Record System\n\n");
		printf("1. Create Account\n2. Display Account\n3. Exit\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				for (i = 0; i < 10; i++) {
					if (accounts[i].accountNumber == 0) {
						createAccount(&accounts[i]);
						break;
					}
				}
				break;

			case 2:
				for (i = 0; i < 10; i++) {
					if (accounts[i].accountNumber!= 0) {
						displayAccount(&accounts[i]);
						break;
					}
				}
				break;

			case 3:
				printf("Exiting...\n");
				return 0;

			default:
				printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}