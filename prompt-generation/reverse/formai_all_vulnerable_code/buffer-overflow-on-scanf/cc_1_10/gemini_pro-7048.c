//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: visionary
// Embark on a quest to locate the elusive element in an ethereal realm of data.

#include <stdio.h>
#include <stdlib.h>

// A mystical array of celestial bodies, each possessing a unique aura.
int celestial_array[] = {42, 17, 3, 9, 11, 13, 19, 23, 29};
#define CELESTIAL_COUNT (sizeof(celestial_array) / sizeof(int))

// The astrologer seeks the celestial body with a specific celestial influence.
int target_influence;

// A binary search algorithm, guided by the stars, to locate the celestial object.
int binary_search(int start, int end) {
    if (start <= end) {
        // Calculate the midpoint of the celestial realm.
        int mid = (start + end) / 2;

        // Query the celestial body at the midpoint.
        if (celestial_array[mid] == target_influence) {
            // The astrologer has found the celestial body!
            return mid;
        } else if (celestial_array[mid] < target_influence) {
            // Search the higher celestial realms.
            return binary_search(mid + 1, end);
        } else {
            // Search the lower celestial realms.
            return binary_search(start, mid - 1);
        }
    }

    // The astrologer has failed to find the celestial body in this realm.
    return -1;
}

// A ritual to summon the astrologer and perform the celestial search.
int main() {
    // The astrologer requests the celestial influence sought.
    printf("Enter the celestial influence you seek, wise one: ");
    scanf("%d", &target_influence);

    // The astrologer embarks on the binary search journey.
    int result = binary_search(0, CELESTIAL_COUNT - 1);

    if (result != -1) {
        // The astrologer has found the celestial body!
        printf("Behold, the celestial body with influence %d is found at position %d!\n", target_influence, result);
    } else {
        // The astrologer has failed to find the celestial body in this realm.
        printf("Alas, the celestial body with influence %d could not be found in this cosmic expanse.\n", target_influence);
    }

    return 0;
}