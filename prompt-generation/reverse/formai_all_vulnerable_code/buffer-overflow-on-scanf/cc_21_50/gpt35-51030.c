//FormAI DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100 // define the maximum number of books

struct Book { // define the structure of a book
	char title[50];
	char author[50];
	char isbn[13];
	int pages;
	float price;
};

int main() {
	struct Book books[MAX_BOOKS]; // define an array of books
	int num_books = 0; // keep track of how many books are in the array

	FILE *fp; // declare a file pointer
	fp = fopen("books.txt", "r"); // open the file for reading

	if (fp != NULL) {
		char line[100]; // a buffer to hold each line of text from the file

		while (fgets(line, sizeof(line), fp) != NULL) { // read each line of text
			char *token;
			char delim[] = ",";
			int i = 0;

			token = strtok(line, delim); // split the line into tokens using comma as the delimiter

			while (token != NULL) {
				switch (i) { // based on the field, add the token to the corresponding struct member
					case 0:	// title
						strcpy(books[num_books].title, token);
						break;
					case 1:	// author
						strcpy(books[num_books].author, token);
						break;
					case 2:	// ISBN
						strcpy(books[num_books].isbn, token);
						break;
					case 3:	// number of pages
						books[num_books].pages = atoi(token);
						break;
					case 4:	// price
						books[num_books].price = atof(token);
						break;
				}

				token = strtok(NULL, delim); // move to the next token
				i++;
			}

			num_books++; // increment the number of books
		}

		fclose(fp); // close the file
	}

	int choice;

	do {
		printf("Ebook Reader\n");
		printf("============\n\n");
		printf("1. Display Books\n");
		printf("2. Add Book\n");
		printf("3. Remove Book\n\n");
		printf("0. Exit\n\n");

		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
				if (num_books > 0) {
					printf("\n%-50s %-20s %-15s %-10s %-10s\n", "Title", "Author", "ISBN", "Pages", "Price");
					printf("------------------------------------------------------------------------------------------------\n");

					for (int i = 0; i < num_books; i++) {
						printf("%-50s %-20s %-15s %-10d $%-9.2f\n", books[i].title, books[i].author, books[i].isbn, books[i].pages, books[i].price);
					}
				} else {
					printf("No books to display\n");
				}

				break;
			}

			case 2: {
				if (num_books == MAX_BOOKS) {
					printf("Maximum number of books reached\n");
				} else {
					printf("\nEnter information for new book:\n");

					printf("Title: ");
					scanf("%s", books[num_books].title);

					printf("Author: ");
					scanf("%s", books[num_books].author);

					printf("ISBN: ");
					scanf("%s", books[num_books].isbn);

					printf("Pages: ");
					scanf("%d", &books[num_books].pages);

					printf("Price: $");
					scanf("%f", &books[num_books].price);

					num_books++; // increment the number of books
					printf("\nBook added successfully!\n");
				}

				break;
			}

			case 3: {
				if (num_books == 0) {
					printf("No books to remove\n");
				} else {
					char isbn[13];
					int found_book = 0;

					printf("Enter ISBN of book to remove: ");
					scanf("%s", isbn);

					for (int i = 0; i < num_books; i++) {
						if (strcmp(isbn, books[i].isbn) == 0) { // if the ISBN matches
							for (int j = i; j < num_books - 1; j++) {
								books[j] = books[j + 1]; // shift the remaining books down in the array
							}

							num_books--; // decrement the number of books

							found_book = 1;
							break; // exit the loop since we found the book
						}
					}

					if (found_book) {
						printf("\nBook removed successfully!\n");
					} else {
						printf("\nBook not found\n");
					}
				}

				break;
			}

			case 0: {
				printf("\nExiting program...\n");
				break;
			}

			default: {
				printf("\nInvalid choice, please try again\n");
				break;
			}
		}

		printf("\nPress ENTER to continue...");
		getchar();
		getchar();

		system("clear"); // for Linux / macOS
		// system("cls"); // for Windows
	} while (choice != 0);

	return 0;
}