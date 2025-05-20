//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define NUM_CHANNELS 14  // Number of Wi-Fi channels

int main() {
  int channel_power[NUM_CHANNELS] = {0};  // Initialize power levels to 0
  int channel_freq[NUM_CHANNELS] = {2412, 2417, 2422, 2427, 2432, 
                                     2437, 2442, 2447, 2452, 2457, 
                                     2462, 2467, 2472, 2484};  // Wi-Fi channel frequencies

  printf("Wi-Fi Signal Strength Analyzer\n\n");

  char input;
  do {
    printf("Enter RSSI (Received Signal Strength Indicator) value (-100 to 0 dBm): ");
    int rssi;
    scanf("%d", &rssi);

    // Determine the channel the Wi-Fi network is on using the frequency
    int channel = -1;
    for (int i = 0; i < NUM_CHANNELS; i++) {
      if (fabs(channel_freq[i] - 2407) <= 5) {
        if (fabs(channel_freq[i] - 2407) < fabs(channel_freq[i] - 2412)) {
          channel_freq[i] = 2407;  // Normalize channel frequency
        } else {
          channel_freq[i] = 2412;  // Normalize channel frequency
        }
      }
      if (fabs(channel_freq[i] - 2484) <= 5) {
        if (fabs(channel_freq[i] - 2484) < fabs(channel_freq[i] - 2472)) {
          channel_freq[i] = 2484;  // Normalize channel frequency
        } else {
          channel_freq[i] = 2472;  // Normalize channel frequency
        }
      }
      if (rssi > (-27.55*log(channel_freq[i]) - 31.04)) {
        channel = i;
        break;
      }
    }

    if (channel == -1) {
      printf("No Wi-Fi networks found within range!");
    } else {
      printf("Wi-Fi network is on channel %d.\n", channel + 1);
      channel_power[channel]++;
      printf("Press enter to continue or 'q' to quit.\n");
    }

    input = getchar();
  } while(input != 'q');

  printf("\nChannel power levels:\n");
  for (int i = 0; i < NUM_CHANNELS; i++) {
    printf("Channel %d: %d\n", i + 1, channel_power[i]);
  }

  return 0;
}