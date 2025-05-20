//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Linus Torvalds style:
// - No curly braces for single-line statements
// - No semicolons at the end of lines
// - Indentation with tabs
// - No whitespace around operators

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

char entries[MAX_ENTRIES][MAX_ENTRY_LEN];
int num_entries = 0;

void add_entry() {
	if (num_entries >= MAX_ENTRIES) {
		printf("Error: diary is full\n");
		return;
	}

	time_t t = time(NULL);
	char *date = ctime(&t);
	printf("Enter your entry for %s: ", date);
	fgets(entries[num_entries], MAX_ENTRY_LEN, stdin);
	num_entries++;
}

void list_entries() {
	if (num_entries == 0) {
		printf("No entries in diary\n");
		return;
	}

	for (int i = 0; i < num_entries; i++) {
		printf("%d: %s\n", i + 1, entries[i]);
	}
}

void delete_entry() {
	int index;
	printf("Enter the index of the entry to delete: ");
	scanf("%d", &index);
	if (index < 1 || index > num_entries) {
		printf("Error: invalid index\n");
		return;
	}

	for (int i = index - 1; i < num_entries - 1; i++) {
		strcpy(entries[i], entries[i + 1]);
	}

	num_entries--;
}

void edit_entry() {
	int index;
	printf("Enter the index of the entry to edit: ");
	scanf("%d", &index);
	if (index < 1 || index > num_entries) {
		printf("Error: invalid index\n");
		return;
	}

	printf("Enter the new entry: ");
	fgets(entries[index - 1], MAX_ENTRY_LEN, stdin);
}

int main() {
	int choice;

	while (1) {
		printf("1. Add entry\n2. List entries\n3. Delete entry\n4. Edit entry\n5. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				add_entry();
				break;
			case 2:
				list_entries();
				break;
			case 3:
				delete_entry();
				break;
			case 4:
				edit_entry();
				break;
			case 5:
				return 0;
			default:
				printf("Error: invalid choice\n");
		}
	}

	return 0;
}