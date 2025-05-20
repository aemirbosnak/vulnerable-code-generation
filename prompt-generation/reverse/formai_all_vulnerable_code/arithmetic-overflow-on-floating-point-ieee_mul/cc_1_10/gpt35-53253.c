//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include<stdio.h>
#include<math.h>

#define RADIUS 6371 // radius of earth in km

double toRadians(double deg) {
  return deg * M_PI / 180;
}

double calcDistance(double lat1, double lon1, double lat2, double lon2) {
  lat1 = toRadians(lat1);
  lon1 = toRadians(lon1);
  lat2 = toRadians(lat2);
  lon2 = toRadians(lon2);

  double dLat = lat2 - lat1;
  double dLon = lon2 - lon1;

  double a = pow(sin(dLat / 2), 2) +
             cos(lat1) * cos(lat2) *
             pow(sin(dLon / 2), 2);

  double c = 2 * atan2(sqrt(a), sqrt(1-a));

  return RADIUS * c;
}

void printDirection(double distance, double bearing) {
  if(bearing > -22.5 && bearing <= 22.5) {
    printf("Travel North for %.2f km.\n", distance);
  } else if(bearing > 22.5 && bearing <= 67.5) {
    printf("Travel Northeast for %.2f km.\n", distance);
  } else if(bearing > 67.5 && bearing <= 112.5) {
    printf("Travel East for %.2f km.\n", distance);
  } else if(bearing > 112.5 && bearing <= 157.5) {
    printf("Travel Southeast for %.2f km.\n", distance);
  } else if(bearing > 157.5 || bearing <= -157.5) {
    printf("Travel South for %.2f km.\n", distance);
  } else if(bearing > -157.5 && bearing <= -112.5) {
    printf("Travel Southwest for %.2f km.\n", distance);
  } else if(bearing > -112.5 && bearing <= -67.5) {
    printf("Travel West for %.2f km.\n", distance);
  } else if(bearing > -67.5 && bearing <= -22.5) {
    printf("Travel Northwest for %.2f km.\n", distance);
  }
}

int main() {
  double lat1, lon1, lat2, lon2;

  printf("Enter starting latitude: ");
  scanf("%lf", &lat1);

  printf("Enter starting longitude: ");
  scanf("%lf", &lon1);

  printf("Enter destination latitude: ");
  scanf("%lf", &lat2);

  printf("Enter destination longitude: ");
  scanf("%lf", &lon2);

  double distance = calcDistance(lat1, lon1, lat2, lon2);
  double bearing = atan2(sin(lon2-lon1)*cos(lat2), cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(lon2-lon1)) * 180/M_PI;

  printDirection(distance, bearing);

  return 0;
}