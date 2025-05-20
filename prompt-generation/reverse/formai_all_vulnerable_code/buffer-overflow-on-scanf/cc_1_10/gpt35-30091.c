//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
// As you enter the world of programming, the first thing that comes to your mind is solving real-world problems with your code. Every program can act as a real hero in saving valuable time and errors. Searching is one such problem-solving technique that you'll come across very often. Let's dive into the world of Searching through this unique C program.

#include <stdio.h>

int main()
{
    // Imagine you're in a treasure hunt! You're trying to find the key to the treasure chest
    // Let's create an array of keys in a random order
    int keys[] = {11, 8, 19, 17, 13, 15, 10, 14, 9, 12};
    int numOfKeys = sizeof(keys) / sizeof(keys[0]);

    // Now let's sort the keys in ascending order
    int i, j, temp;
    for(i = 0; i < numOfKeys; i++) {
        for(j = i+1; j < numOfKeys; j++) {
            if(keys[i] > keys[j]) {
                temp = keys[i];
                keys[i] = keys[j];
                keys[j] = temp;
            }
        }
    }

    // You're now at the starting point of the hunt and you have a list of sorted keys
    // You can either start searching from one end or you can be smart about it
    int searchKey, start, end, mid;
    printf("Enter the value of the key you are searching for: ");
    scanf("%d", &searchKey);

    start = 0;
    end = numOfKeys - 1;
    while(start <= end) {
        mid = (start + end) / 2;
        if(searchKey == keys[mid]) {
            printf("The key you are searching for is at index %d!\n", mid);
            return 0;
        }
        else if(searchKey < keys[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    // If you've reached here, it means that the key is not in the list of keys
    printf("Sorry, the key you are searching for is not in the list.\n");

    return 0;
}