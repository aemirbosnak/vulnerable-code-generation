//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// The world has been ravaged by nuclear war, and the only survivors are a group 
// of scavengers who roam the wasteland in search of food and supplies.
// One day, the scavengers come across a cache of ammo boxes, each containing a 
// different type of ammunition. The scavengers need to sort the ammo boxes by 
// caliber so that they can use the ammo in their weapons.

// The scavengers use a bucket sort algorithm to sort the ammo boxes.
// Bucket sort is a sorting algorithm that works by distributing the elements of a 
// list into a number of buckets.
// Each bucket is identified by a key, and the elements in the list are distributed 
// into the buckets based on their key values.
// Once the elements have been distributed into the buckets, the buckets are sorted.
// Finally, the elements in the buckets are concatenated to form the sorted list.

// In the case of the scavengers, the key values are the calibers of the ammo 
// boxes.
// The scavengers create a bucket for each caliber, and they distribute the ammo 
// boxes into the buckets based on their calibers.
// Once the ammo boxes have been distributed into the buckets, the scavengers sort 
// the buckets.
// Finally, the scavengers concatenate the elements in the buckets to form the 
// sorted list of ammo boxes.

int main()
{
   // The scavengers find a cache of ammo boxes.
   int ammo_boxes[] = {10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
   int num_ammo_boxes = sizeof(ammo_boxes) / sizeof(int);

   // The scavengers create a bucket for each caliber.
   int buckets[30];

   // The scavengers distribute the ammo boxes into the buckets.
   for (int i = 0; i < num_ammo_boxes; i++)
   {
      buckets[ammo_boxes[i]]++;
   }

   // The scavengers sort the buckets.
   for (int i = 0; i < 30; i++)
   {
      if (buckets[i] > 0)
      {
         for (int j = 0; j < buckets[i]; j++)
         {
            printf("%d ", i);
         }
      }
   }

   return 0;
}