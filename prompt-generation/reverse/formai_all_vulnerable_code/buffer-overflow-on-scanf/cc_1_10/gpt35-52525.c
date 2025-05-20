//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char book_title[30];
    char author[20];
    int year_published;
    double price;
} Book;

int main() {
    FILE *fp;
    Book book_list[5];
    int i, count = 0;
    char c;

    // Open file for writing
    fp = fopen("books.txt", "w");

    // Check if file was opened successfully
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Obtain input from user and write to file
    do {
        printf("Enter book title: ");
        fgets(book_list[count].book_title, 30, stdin);
        printf("Enter author: ");
        fgets(book_list[count].author, 20, stdin);
        printf("Enter year published: ");
        scanf("%d", &book_list[count].year_published);
        printf("Enter price: ");
        scanf("%lf", &book_list[count].price);
        count++;
        printf("Do you want to enter another book? (y/n): ");
        scanf(" %c", &c);
        getchar(); // consume the newline character left behind by scanf
    } while (c == 'y' && count < 5);

    // Write data to file
    for (i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n%d\n%f\n", book_list[i].book_title, book_list[i].author, book_list[i].year_published, book_list[i].price);
    }

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("books.txt", "r");

    // Check if file was opened successfully
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Read data from file and print to console
    printf("\nBook List:\n");
    while(fscanf(fp, "%[^\n]%*c%[^\n]%*c%d%lf\n", book_list[count].book_title, book_list[count].author, &book_list[count].year_published, &book_list[count].price) != EOF) {
        printf("%d. %s by %s, published in %d, price: %f\n", count+1, book_list[count].book_title, book_list[count].author, book_list[count].year_published, book_list[count].price);
        count++;
    }

    // Close file
    fclose(fp);

    return 0;
}