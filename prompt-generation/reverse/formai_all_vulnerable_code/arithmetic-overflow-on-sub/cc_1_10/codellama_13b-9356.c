//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
int main() {
    // Declare variables
    int n, i, j, k, temp;
    float sum;
    char name[100], artist[100];

    // Initialize variables
    n = 0;
    sum = 0.0;

    // Take input from user
    printf("Enter the number of songs: ");
    scanf("%d", &n);

    // Declare arrays to store song names and artist names
    char *song_names[n];
    char *artist_names[n];

    // Take input for song names and artist names
    for (i = 0; i < n; i++) {
        printf("Enter song name %d: ", i + 1);
        scanf("%s", &song_names[i]);
        printf("Enter artist name %d: ", i + 1);
        scanf("%s", &artist_names[i]);
    }

    // Sort the arrays by song names
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(song_names[i], song_names[j]) > 0) {
                temp = song_names[i];
                song_names[i] = song_names[j];
                song_names[j] = temp;

                temp = artist_names[i];
                artist_names[i] = artist_names[j];
                artist_names[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted song names:\n");
    for (i = 0; i < n; i++) {
        printf("%s - %s\n", song_names[i], artist_names[i]);
    }

    // Calculate the total duration of all songs
    for (i = 0; i < n; i++) {
        sum += strlen(song_names[i]) * strlen(artist_names[i]);
    }

    // Print the total duration
    printf("Total duration: %.2f minutes\n", sum / 60);

    return 0;
}