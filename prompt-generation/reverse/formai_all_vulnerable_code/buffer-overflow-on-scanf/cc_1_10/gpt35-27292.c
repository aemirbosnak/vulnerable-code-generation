//FormAI DATASET v1.0 Category: Database Indexing System ; Style: funny
int main() {
    printf("Hey there! Starting up the Database Indexing System... but first, let me take a SQLfie!\n");

    // Initializing database
    int dataset[100] = {1, 6, 4, 8, 3, 9, 7, 2, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(dataset) / sizeof(dataset[0]);

    printf("Initializing database... Done!\n");

    // Sorting dataset
    printf("Sorting dataset...\n");
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(dataset[i] > dataset[j]) {
                int temp = dataset[i];
                dataset[i] = dataset[j];
                dataset[j] = temp;
            }
        }
    }

    printf("Sorted dataset... Done!\n");
    printf("Creating index...\n");

    // Creating index
    int index[100] = {};
    for(int i=0; i<size; i++) {
        index[dataset[i]] = i+1;
    }

    printf("Index created... Done!\n");

    // Performing search
    printf("Search test: Enter a number you'd like to search in the database: ");

    int search;
    scanf("%d", &search);

    if(search >= 1 && search <= size) {
        if(index[search])
            printf("Found it! Number %d is at index %d in the database.\n", search, index[search]);
        else
            printf("Oops! Number %d is not in the database.\n", search);
    } else {
        printf("Invalid number entered!\n");
    }

    printf("Thanks for using the Database Indexing System. Please recycle this program responsibly and don't forget to smile today :)\n");
    return 0;
}