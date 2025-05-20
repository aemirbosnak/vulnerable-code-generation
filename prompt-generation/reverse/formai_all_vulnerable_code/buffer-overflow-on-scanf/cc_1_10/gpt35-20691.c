//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
// Welcome to our Electronic Voting System!
// This program is designed to help with the election process by providing a user-friendly voting interface
// and storing the data securely in a database. Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Define the database file and create table query
static char *database_name = "voters.db";
static char *table_query = "CREATE TABLE IF NOT EXISTS voters(name TEXT, age INT, voted BOOL);";

// Create the connection to the database
static sqlite3 *connect_to_database(){
    sqlite3 *db;
    int rc;

    // Try to open connection to the database, exit program if there's an error
    rc = sqlite3_open(database_name, &db);
    if(rc){
        fprintf(stderr, "Error: Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    return db;
}

// Check if table exists in database, create it if not
static void create_table_if_not_exists(sqlite3 *db){
    char *zErrMsg = 0;
    int rc;

    // Execute the table creation query, exit program if there's an error
    rc = sqlite3_exec(db, table_query, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        exit(1);
    }
}

// Insert voter information into the database
static void insert_voter_info(sqlite3 *db, char *name, int age, int voted){
    char *zErrMsg = 0;
    int rc;

    // Generate insert query string and execute it, exit program if there's an error
    char query[100];
    sprintf(query, "INSERT INTO voters VALUES ('%s', %d, %d);", name, age, voted);
    rc = sqlite3_exec(db, query, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

// Check if the voter has already voted
static int has_voted(sqlite3 *db, char *name){
    sqlite3_stmt *stmt;
    char query[100];
    int rc;

    // Generate select query string and execute it, exit program if there's an error
    sprintf(query, "SELECT voted FROM voters WHERE name = '%s';", name);
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Get the result of the select query
    int has_voted = 0;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        has_voted = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return has_voted;
}

// Display the voting options and get the user's vote
static int get_user_vote(){
    int vote;

    // Display the options
    printf("Please select your vote:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");

    // Get the user's input
    scanf("%d", &vote);

    return vote;
}

// Display the election results
static void show_election_results(sqlite3 *db){
    sqlite3_stmt *stmt;
    char query[100];
    int rc;

    // Generate select query string and execute it, exit program if there's an error
    sprintf(query, "SELECT COUNT(*) FROM voters WHERE voted = 1;");
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Get the result of the select query
    int total_voters = 0;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        total_voters = sqlite3_column_int(stmt, 0);
    }

    // Generate select query string and execute it, exit program if there's an error
    sprintf(query, "SELECT COUNT(*) FROM voters WHERE voted = 1 AND name = 'Candidate A';");
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Get the result of the select query
    int candidate_a_votes = 0;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        candidate_a_votes = sqlite3_column_int(stmt, 0);
    }

    // Generate select query string and execute it, exit program if there's an error
    sprintf(query, "SELECT COUNT(*) FROM voters WHERE voted = 1 AND name = 'Candidate B';");
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Get the result of the select query
    int candidate_b_votes = 0;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        candidate_b_votes = sqlite3_column_int(stmt, 0);
    }

    // Generate select query string and execute it, exit program if there's an error
    sprintf(query, "SELECT COUNT(*) FROM voters WHERE voted = 1 AND name = 'Candidate C';");
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        exit(1);
    }

    // Get the result of the select query
    int candidate_c_votes = 0;
    while(sqlite3_step(stmt) == SQLITE_ROW){
        candidate_c_votes = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);

    // Display the results
    printf("\nElection Results:\n");
    printf("# of voters: %d\n", total_voters);
    printf("Candidate A: %d votes\n", candidate_a_votes);
    printf("Candidate B: %d votes\n", candidate_b_votes);
    printf("Candidate C: %d votes\n", candidate_c_votes);
}

int main(){

    // Connect to the database and create the table if it doesn't exist
    sqlite3 *db = connect_to_database();
    create_table_if_not_exists(db);

    // Get voter information and check if they have already voted
    char name[50];
    int age;
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    int voter_has_voted = has_voted(db, name);

    if(voter_has_voted){
        printf("Sorry %s, you have already voted!\n", name);
    }else{

        // Get the user's vote and insert the data into the database
        int vote = get_user_vote();
        printf("Thank you for voting!\n");
        insert_voter_info(db, name, age, 1);
    }

    // Display the election results
    show_election_results(db);

    // Close the database connection
    sqlite3_close(db);

    return 0;
}