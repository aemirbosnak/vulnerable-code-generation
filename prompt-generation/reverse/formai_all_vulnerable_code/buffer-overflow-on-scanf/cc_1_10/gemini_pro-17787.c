//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#define ASSETS_SIZE 4
#define DEPOSIT -1
#define WITHDRAW 1
#define LAT "Latitude"
#define LONG "Longitude"
#define ELE "Elevation"
#define CUR "Current"
#define DEL "Delta"
#define DEP "Deposit"
#define WIT "Withdraw"
#define EARNING "Earnings"

#define GPS_LAT_STR "% 3.3f "
#define GPS_LONG_STR "% 4.4f "
#define GPS_ELE_STR "% 3.3f "

typedef struct {
  float lat, lon, ele;
} GPS;

typedef struct {
  float amt, earning;
  int typ;
} MONEY;

typedef struct {
  char n[16];
  GPS latlong;
  float bal;
  MONEY money[10];
} ACCOUNT;

int main() {
  ACCOUNT acc[] = {{"Alex's Checking", {37.38, -122.08, 32.0}, 2000.0,
                                           {{100.0, 0.01, DEPOSIT}, {250.0, 0.03, DEPOSIT}}},
                    {"Alex's Savings", {37.29, -121.97, 12.2}, 10000.0,
                                            {{500.0, 0.05, DEPOSIT}, {1000.0, 0.07, DEPOSIT}}},
                    {"Mary's Checking", {37.78, -122.40, 34.0}, 4000.0,
                                           {{150.0, 0.01, DEPOSIT}, {300.0, 0.02, DEPOSIT}}},
                    {"Mary's Savings", {37.61, -122.29, 23.1}, 8000.0,
                                            {{550.0, 0.05, DEPOSIT}, {1200.0, 0.06, DEPOSIT}}}};
  int numOfAccounts = sizeof(acc), choice, acct;
  float amt;
  GPS gps;
  printf("Welcome to your Personal Finance Planner!\n");
  while (1) {
    printf("1. View account balances\n2. Make a deposit\n3. Make a withdrawal\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        for (acct = 0; acct < numOfAccounts; acct++) {
          printf("Account: %s\n", acc[acct].n);
          printf("Balance: %.2f\n", acc[acct].bal);
          printf("GPS Location:\n");
          printf("\tLatitude: " GPS_LAT_STR "\n", acc[acct].latlong.lat);
          printf("\tLongitude: " GPS_LONG_STR "\n", acc[acct].latlong.lon);
          printf("\tElevation: " GPS_ELE_STR "\n", acc[acct].latlong.ele);
        }
        break;
      case 2:
        printf("Enter account number (1-%d): ", numOfAccounts);
        scanf("%d", &acct);
        printf("Enter amount to deposit: ");
        scanf("%f", &amt);
        acc[acct - 1].bal += amt;
        acc[acct - 1].money[acc[acct - 1].money[0].typ == DEPOSIT ? 0 : 1].amt += amt;
        printf("Deposit successful!\n");
        break;
      case 3:
        printf("Enter account number (1-%d): ", numOfAccounts);
        scanf("%d", &acct);
        printf("Enter amount to withdraw: ");
        scanf("%f", &amt);
        if (amt <= acc[acct - 1].bal) {
          acc[acct - 1].bal -= amt;
          acc[acct - 1].money[acc[acct - 1].money[0].typ == DEPOSIT ? 0 : 1].amt -= amt;
          printf("Withdrawal successful!\n");
        } else {
          printf("Insufficient funds!\n");
        }
        break;
      case 4:
        exit(0);
    }
  }
  return 0;
}